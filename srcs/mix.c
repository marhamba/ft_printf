#include "ft_printf.h"

void     make_zeros()
{
    flags.width = 0;
    flags.minus = 0;
    flags.dot = 0;
    flags.prec = 0;
    flags.star = 0;
	flags.arg = 0;
	flags.zero = 0;
	flags.negative = 0;
    flags.isprec = 0;
    flags.pz = 1;
}

int		ft_dot_function(char *format)
{
	if (*format == '.')
		format++;
	if (*format == '*')
	{
		flags.prec = va_arg(flags.list, int);
	}
	else if (*format >= '0' && *format <= '9')
	{
		flags.prec = ft_atoi(format);
	}
	format++;
	ft_check_convs(format);
	return (0);
}

void     ft_check_format(char *format)
{
	if (*format == '%')
		format++;
	if (*format == '*')
    {
        flags.star = 1;
        flags.width = va_arg(flags.list, int);
    	format++;
	}
	else if (*format >= '0' && *format <= '9')
	{
		ft_dot_function(format);
		while (*format >= '0' && *format <= '9')
			format++;
    }
}

void	ft_check_convs(char *format)
{
		if (*format == 'd' || *format == 'i')
		{
			flags.arg = va_arg(flags.list, int);
			ft_treat_decimal();
		}
		else if (*format == 'c')
		{
			flags.arg = va_arg(flags.list, int);
			ft_treat_char();
		}
		else if (*format == 's')
		{
			flags.string = va_arg(flags.list, char *);
			ft_treat_string(format);
		}
}

// void     ft_check_flags(const char *format)
// {
// 	while (!(*format >= '1' && *format <= '9'))
// 	{
// 		if (*format == '-' || *format == '0')
// 		{
// 			(*format == '-') ? flags.minus = 1 : 0;
// 			(*format == '0') ? flags.zero = 1 : 0;
// 		}
// 		else if (*format != '-' || *format != '0')
// 		if (*format == '.')
// 			flags.dot = 1;
// 		if (*format == '*')
// 			flags.star = 1;
// 		(*format == '.') ? flags.dot = 1 : 0;
// 		(*format == '*') ? flags.star = 1 : 0;
// 		format++;
// 	}
// }

void	ft_printf2(char *print)
{
	while (*print)
	{
		if (*print == '%')
		{
			make_zeros();
			print++;
				while (*print == '0' || *print == '-')
				{
					if (*print == '0' || *print == '-')
					{
						if (*print == '0')
							flags.zero = 1;
						else
							flags.minus = 1;	
					}
					print++;
				}
				if (flags.minus && flags.zero)
					flags.zero = 0;
				if (*print == '*')
				{
					flags.width = va_arg(flags.list, int);
					if (flags.width < 0 && (flags.minus || !flags.zero))
						{
							flags.minus = 1;
							flags.zero = 0;
							flags.width *= (-1);
						}
					print++;
				}
				else if (*print >= '0' && *print <= '9')
				{
					flags.width = ft_atoi(print);
					while (*print >= '0' && *print <= '9')
						print++;
				}
				if (*print == '.')
				{
					flags.dot = 1;
					print++;
					if (*print == '*')
					{
						flags.star = 1;
						flags.prec = va_arg(flags.list, int);
						if (flags.prec == 0)
							flags.isprec = 1;
						if (flags.prec < 0)
							flags.prec = 0;
						print++;
					}
					else if (*print >= '0' && *print <= '9')
					{
						flags.prec = ft_atoi(print);
						if (flags.prec == 0)
							flags.isprec = 1;
						while (*print >= '0' && *print <= '9')
							print++;
					}
				}
			ft_check_convs(print);
			print++;
			continue;
		}
		ft_putchar(*print);
		print++;
	}
}