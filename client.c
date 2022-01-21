/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:15:49 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/21 02:08:38 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void	char_to_bits(char c, pid_t pid)
{
	unsigned int	bit;

	bit = -1;
	while (++bit < 7)
	{
		if (1 & (c >> bit))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(200);
	}
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
