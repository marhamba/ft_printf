/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:18:16 by tumolabs          #+#    #+#             */
/*   Updated: 2021/07/23 19:01:04 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_convs(char *format)
{
	int	mek;

	mek = 0;
	if (*format == 'd' || *format == 'i')
	{
		g_flags.arg = va_arg(g_flags.list, int);
		ft_treat_decimal(mek);
	}
	else if (*format == 'c')
	{
		g_flags.arg = va_arg(g_flags.list, int);
		ft_putchar(g_flags.arg);
	}
	else if (*format == 's')
	{
		g_flags.string = va_arg(g_flags.list, char *);
		if (g_flags.string == NULL)
		{
			ft_putstr("(null)");
			return ;
		}
		ft_putstr(g_flags.string);
	}
	ft_check_convs2(format);
}

void	ft_check_convs2(char *format)
{
	int	mek;

	mek = 0;
	if (*format == 'u')
		ft_treat_unsigned(mek);
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'X')
			g_flags.areg = 1;
		else
			g_flags.areg = 0;
		ft_treat_hexa(mek);
		g_flags.unsignedd = 1;
	}
	else if (*format == 'p')
		ft_treat_pointer(mek);
	else if (*format == '%')
		ft_putchar('%');
}
