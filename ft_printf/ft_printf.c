/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:15:31 by marhamba          #+#    #+#             */
/*   Updated: 2021/06/02 21:34:05 by marhamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_flags     make_zeros(t_flags flags)
{
    flags.width = 0;
    flags.minus = 0;
    flags.dot = -1;
    flags.prec = 0;
    flags.star = 0;
    return (flags);
}


//d-i hamar flager stugel
int     ft_check_format(char **format)
{
    format++;
    if (**format >= '0' && **format <= '9')
	{
        flags.width = ft_atoi(*format);
    	format++;
	}
	else if (**format == '*')
    {
        flags.star = 1;
        flags.width = va_arg(flags.list, int);
    	format++;
	}
    if (**format == '.')
    {
        if (++**format == '*')
            flags.prec = va_arg(flags.list, int);
        else if (**format >= '0' && **format <= '9')
            flags.prec = ft_atoi(++*format);
	}
	format++;
	ft_check_convs(format);
	return (0);
}

void	ft_check_convs(char **format)
{
	if (**format == 'd' || **format == 'i')
		ft_treat_decimal();
	//else if (**format == 'c')
	//	ft_treat_char();
	//else if (**format == 's')
	//	ft_treat_string();
	//else if (**format == 'u')
	//	ft_treat_unsigned();
//	else if (**format == 'x' || **format == 'X')
//		ft_treat_hexa();
//	else if (**format == 'p')
//		ft_treat_pointer();
//	else if (**format == '%')
//		ft_treat_percent();
}




void	print_minus1(int	space, char *charg)
{
	while (flags.zero--)
		ft_putchar('0');
	ft_putstr(charg);
	while (space--)
		ft_putchar(' ');
}

void	print_minus0(int	space, char *charg)
{
	while (space--)
		ft_putchar(' ');
	while (flags.zero--)
		ft_putchar('0');
	ft_putstr(charg);
}

void	ft_minus_cases(int len, int space, char	*charg)
{
	if (flags.width > flags.prec && flags.prec > len)
		print_minus0(space, charg);
	else if (flags.width < flags.prec && flags.width > len) 
		print_minus1(0, charg);
	else if (flags.width > len && flags.prec < len)
		print_minus0(flags.width - len, charg);
	else
		ft_putstr(charg);
}

void	ft_notminus_cases(int len, int space, char *charg)
{
	
	if (flags.width > flags.prec && flags.prec > len)
		print_minus1(space, charg);
	else if (flags.width < len && flags.prec > len)
		print_minus1(0, charg);
	else if (flags.width < flags.prec && flags.width > len)
		print_minus1(0, charg);
	else if (flags.width > len && flags.prec < len)
		print_minus1(flags.width - len, charg);
	else
		ft_putstr(charg);
}

void	ft_treat_char()
{
	int		arg;
	int		space;

	arg = va_arg(flags.list, char);
	space = flags.width - 1;
	if (flags.width > 0)


}

void	ft_treat_decimal()
{
	int		arg; //va_argic vercracy tiv
	int		len;
	char	*charg; //argi char sarqac tesaky
	int		space;

	arg = va_arg(flags.list, int);
	charg = ft_itoa(arg);
	len = ft_strlen(charg);
	flags.zero -= len;
	space = flags.width - flags.prec;
	if (flags.minus == 0)
		ft_minus_cases(len, space, charg);
	else
		ft_notminus_cases(len, space, charg);
}


void     ft_check_flags(const char **format)
{
    if (**format == '0' || **format == '-')
    {
        if (**format == '-')
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
	char *print;

	print = (char *)format;
    res = 0;
    if (!(print = malloc(sizeof(t_flags))))
        return (-1);
    make_zeros(flags);
    while (*format != '%')
    {
        write(1, &format, 1);
        format++;
    }
    (*format == '%') ? ft_check_flags(&format) : ft_check_format(&print);
	return (flags.count);	
}
