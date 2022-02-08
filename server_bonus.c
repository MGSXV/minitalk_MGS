/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:02:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/02/08 04:39:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef struct s_init{
	int		i;
	char	c;
	int		client_pid;
	int		old_client_pid;
	char	last_char;
}	t_init;

void	reset_count(int *i, char *c)
{
	*i = 0;
	*c = 0;
}

void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	static t_init	srv_req;

	context = NULL;
	srv_req.client_pid = siginfo->si_pid;
	if (srv_req.client_pid != srv_req.old_client_pid)
	{
		if ((srv_req.last_char >> 8 & 1))
			ft_printf("%c", 8);
		reset_count(&srv_req.i, &srv_req.c);
	}
	srv_req.old_client_pid = srv_req.client_pid;
	if (signum == SIGUSR1)
		srv_req.c = (1 << srv_req.i) | srv_req.c;
	if (srv_req.i == 7)
	{
		if (srv_req.c == 0)
			kill(siginfo->si_pid, SIGUSR1);
		ft_printf("%c", srv_req.c);
		srv_req.last_char = srv_req.c;
		reset_count(&srv_req.i, &srv_req.c);
	}
	else
		srv_req.i++;
}

int	main(void)
{
	pid_t				my_pid;
	struct sigaction	sa_h;

	sa_h.sa_flags = SA_SIGINFO;
	sa_h.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa_h, NULL);
	sigaction(SIGUSR2, &sa_h, NULL);
	my_pid = getpid();
	ft_printf("Server's PID: %d\n", my_pid);
	while (1)
		pause();
}
