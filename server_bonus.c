/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:02:29 by sel-kham          #+#    #+#             */
/*   Updated: 2022/02/06 15:08:46 by sel-kham         ###   ########.fr       */
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
	static int	client_pid;
	static int	old_client_pid;

	context = NULL;
	client_pid = siginfo->si_pid;
	if (client_pid != old_client_pid)
	{
		i = 0;
		c = 0;		
	}
	old_client_pid = client_pid;
	if (signum == SIGUSR1)
		c = (1 << i) | c;
	if (i == 7)
	{
		if (c == 0)
			kill(siginfo->si_pid, SIGUSR1);
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
