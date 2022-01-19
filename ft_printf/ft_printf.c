/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:31:56 by sel-kham          #+#    #+#             */
/*   Updated: 2021/12/15 16:52:56 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ts_handler(va_list ap, char c, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), i);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), i);
	else if (c == 'd')
		ft_putnbr_base("0123456789", va_arg(ap, int), i);
	else if (c == 'i')
		ft_putnbr_base("0123456789", va_arg(ap, int), i);
	else if (c == 'u')
		ft_putnbr_base("0123456789", va_arg(ap, unsigned int), i);
	else if (c == 'x')
		ft_putnbr_base("0123456789abcdef", va_arg(ap, unsigned int), i);
	else if (c == 'X')
		ft_putnbr_base("0123456789ABCDEF", va_arg(ap, unsigned int), i);
	else if (c == 'p')
	{
		ft_putstr("0x", i);
		ft_putnbr_base_p("0123456789abcdef", va_arg(ap, unsigned long), i);
	}
	else if (c == '%')
		ft_putchar('%', i);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = -1;
	count = 0;
	va_start(ap, fmt);
	while (fmt[++i])
	{
		if (fmt[i] != '%')
			ft_putchar(fmt[i], &count);
		else
		{
			if (ft_strchr("cspdiuxX%", fmt[++i]))
				ts_handler(ap, fmt[i], &count);
			else
				ft_putchar(fmt[i], &count);
		}
	}
	va_end(ap);
	return (count);
}
