/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:02:41 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/21 19:39:23 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void	confermation_signal(int signum)
{
	ft_printf("The message sent successfully to the server!!");
}

void	char_to_bits(char c, pid_t pid)
{
	unsigned int	bit;

	bit = -1;
	while (++bit < 32)
	{
		if (1 & (c >> bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error while sending the signal!\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error while sending the signal!\n");
				exit(1);
			}
		}
		usleep(200);
	}
	pause();
	signal(SIGUSR1, &confermation_signal);
}

void	send_signal(pid_t pid, char *msg)
{
	int	i;

	i = -1;
	while (msg[++i])
		char_to_bits(msg[i], pid);
}

int	main(int c, char **v)
{
	int		server_pid;

	if (c != 3)
	{
		ft_printf("Pass only Server's PID and the message as arguments!\n");
		exit(1);
	}
	server_pid = ft_atoi(v[1]);
	if (server_pid <= 0)
	{
		ft_printf("Server's PID can't be equals to or less than 0!\n");
		exit(1);
	}
	send_signal(server_pid, v[2]);
}
