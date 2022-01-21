/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:16:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/21 01:49:08 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> /* various type definitions, like pid_t */
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"


void	sig_handler(int signum)
{
	static int	i;
	static char	c;

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
	pid_t	my_pid;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	my_pid = getpid();
	ft_printf("Server's PID: %d\n", my_pid);
	while (1)
		pause();
}
