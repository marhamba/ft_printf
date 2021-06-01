/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:15:31 by marhamba          #+#    #+#             */
/*   Updated: 2021/05/31 15:18:56 by marhamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_flags     make_zeros(t_flags flags)
{
    flags.width = 0;
    flags.minus = 0;
    flags->dot = -1;
    flags.prec = 0;
    flags.star = 0;
    return (flags);
}


//d-i hamar flager stugel
int     ft_check_format(const char *format, va_list list)
{
    format++;
    if (*format >= '0' && *format <= '9')
        flags.width = ft_atoi(*format);
    else if (*format == '*')
    {
        flags.star = 1;
        flags.width = va_arg(list, int);
    }
    if (*format = '.')
    {
        if (++*format == '*')
            flags.prec = va_arg(list, int);
        else
            flags.prec = ft(atoi(++*format));
}

t_flags     ft_check_flags(const char *format, t_flags flags)
{
    if (*format == '0' || *format == '-')
    {
        if (*format == '-')
        {
            flags.zero = 0;
            flags.minus = 1;
        }
        else
        {
            flags.zero = 1;
            flags.minus = 0;
        }
    }
}


int		ft_printf(const char *format, ...)
{
	int res;
    const char *;

    res = 0;
    if (!(print = malloc(sizeof(t_flags))))
        return (-1);
    make_zeros(flags);
    while (*format != '%')
    {
        write(1, &format, 1);
        format++;
    }
    if (*format == '%')
        ft_check_flags(*format, flags);
        ft_check_format(*format, list);
}
