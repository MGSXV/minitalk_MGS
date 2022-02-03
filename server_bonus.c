/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:02:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/02/03 14:14:05 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	i;
	static char	c;
	static int	server_pid;
	static int	old_server_pid;

	context = NULL;
	server_pid = siginfo->si_pid;
	if (server_pid != old_server_pid)
	{
		i = 0;
		c = 0;
	}
	old_server_pid = server_pid;
	if (signum == SIGUSR1)
		c = (1 << i) | c;
	if (i == 6)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		i++;
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
