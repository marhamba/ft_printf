/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:12:12 by tumolabs          #+#    #+#             */
/*   Updated: 2021/07/23 18:59:58 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_zeros(int mek)
{
	mek = 0;
	g_flags.arg = 0;
	g_flags.unarg = 0;
	g_flags.areg = 0;
	g_flags.point = 0;
	g_flags.string = 0;
	g_flags.unsignedd = 0;
}

void	ft_printf2(char *print)
{
	int	mek;

	mek = 0;
	while (*print)
	{
		if (*print == '%')
		{
			make_zeros(mek);
			print++;
			ft_check_convs(print);
			print++;
			continue ;
		}
		ft_putchar(*print);
		print++;
	}
}

int	ft_printf(const char *format, ...)
{
	char	*print;

	g_flags.count = 0;
	va_start(g_flags.list, format);
	print = (char *)format;
	ft_printf2(print);
	va_end(g_flags.list);
	return (g_flags.count);
}
