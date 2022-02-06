/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 03:02:41 by sel-kham          #+#    #+#             */
/*   Updated: 2022/02/06 02:54:19 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void	confirm_receiving(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("The message received successfully by the server.\n");
}

void	ft_error(char *err_msg)
{
	ft_printf(err_msg);
	exit(1);
}

void	char_to_bits(char c, pid_t pid)
{
	int	bit;

	bit = -1;
	if (c == 0)
		signal(SIGUSR1, &confirm_receiving);
	while (++bit <= 7)
	{
		if (1 & (c >> bit))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("Error while sending the signal!\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("Error while sending the signal!\n");
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
	char_to_bits(msg[i], pid);
}

int	main(int c, char **v)
{
	int		server_pid;

	if (c != 3)
		ft_error("Pass only Server's PID and the message as arguments!\n");
	server_pid = ft_atoi(v[1]);
	if (server_pid <= 0)
		ft_error("Server's PID can't be equals to or less than 0!\n");
	send_signal(server_pid, v[2]);
}
