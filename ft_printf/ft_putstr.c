/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:07:33 by sel-kham          #+#    #+#             */
/*   Updated: 2022/01/21 02:19:21 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	if (len == -1)
		ft_putstr("(null)", count);
	i = -1;
	while (++i < len)
		ft_putchar(s[i], count);
}
