/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:15:49 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/19 23:10:05 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> /* various type definitions, like pid_t */
#include <signal.h>
#include "./libft/libft.h"
//#include "./ft_printf/ft_printf.h"

int	main(int c, char **v)
{
	pid_t	my_pid;
	int		server_pid;
	
	if (c < 3)
		return (printf("You need to pass Server's PID as argument!\n\n"), 0);
	//server_pid = ft_atoi(v[1]);
	printf("Server's PID: %d\n", server_pid);
	kill(7137, SIGUSR1);
}