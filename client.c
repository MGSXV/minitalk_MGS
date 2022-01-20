/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:15:49 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/20 13:49:12 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> /* various type definitions, like pid_t */
#include <signal.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

int	main(int c, char **v)
{
	int		server_pid;

	if (c != 3)
	{
		ft_printf("You need to just pass Server's PID and the message as arguments!\n");
		exit(1);
	}
	server_pid = ft_atoi(v[1]);
	ft_printf("Messgae sent to: %d\n", server_pid);
	kill(server_pid, SIGUSR1);
}
