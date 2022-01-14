/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:16:02 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/15 00:39:16 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> /* various type definitions, like pid_t */

int	main(int c, char **v)
{
	pid_t	my_pid;
	
	if (c < 2)
		return (0);
	my_pid = getpid();
}