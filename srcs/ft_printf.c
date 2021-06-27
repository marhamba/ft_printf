#include "ft_printf.h"


void     make_zeros()
{
    flags.width = 0;
    flags.minus = 0;
    flags.dot = 0;
    flags.prec = 0;
    flags.star = 0;
	flags.arg = 0;
	flags.count = 0;
	flags.zero = 0;
	flags.negative = 0;
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
			// printf("arg -- %d", flags.arg);
			// if (*format-- == '%')
			// {
			// 	if (flags.arg == 0)
			// 		ft_putchar('0');
			// }	
			ft_treat_decimal(format);
		}
		else if (*format == 'c')
		{
			if (*format-- == '%')
				flags.arg = va_arg(flags.list, int);
			ft_treat_char();
		}
}

void	ft_treat_char()
{
	// int space;

	flags.arg = va_arg(flags.list, int);
	if (flags.prec != 0 && flags.dot != 0)
		return ;
	// if (flags.width > 0)
	// // space = flags.width - 1;
	// while (space)
	// {
	// 	ft_putchar(' ');
	// 	space--;
	// }
	// printf("av - %c\n", flags.arg);
	ft_putchar(flags.arg);
}

void	ft_treat_decimal(char *print)
{
	char	*charg;
	int		len;
	int		space;
	int		zero;
	int		zp; //zero printed
	// int	a;
	zp = 0;
	(void)print;
	// a = ft_strlen(ft_itoa((int)flags.print)) + 1;
	// flags.arg = va_arg(flags.list, int);
	// if (!(charg = malloc(a)))
	// 	return ;
	// charg = ft_itoa(flags.arg);
	// printf("%s\n\n\n", charg);
	// charg[a] = '\0';
	// charg = ft_itoa(flags.arg);
	if (flags.arg < 0)
	{
		flags.negative = 1;
		flags.arg = flags.arg * (-1);
	}
	charg = ft_itoa(flags.arg);
	len = ft_strlen(charg);
	// if (flags.negative == 1)
	// {
	// 	zero = flags.prec - len - 1;
	// 	if (flags.width == 0)
	// 		space = 0;
	// 	else
	// 		space = flags.width - len - 1;
	// }
	// else
	// {
	// 	space = flags.width - len;
	// 	zero = flags.prec - len;
	// }
	// zero = flags.zero ? flags.width - len : flags.prec - len;
	// printf("\n\n\n\n%d\n\n\n\n", flags.dot);
	if (flags.negative)
		len++;
	if (flags.negative && flags.zero)
		zero = flags.width - len;
	else if (flags.negative && flags.dot)
	{
		zero = flags.prec - (len - 1);
	}
	else
		zero = flags.zero ? flags.width - len : flags.prec - len;
	space = flags.width - len;
	if (flags.dot && flags.prec > len)
		space -= zero;
	// printf("len ---%d\n", len);
	// if (flags.minus == 0)
	// 	ft_notminus_cases(len, space, zero, &charg, print);
	// else
	// 	ft_minus_cases(len, space, zero, &charg);
	// if ((flags.minus && flags.width > len) || (flags.dot))
	if (flags.minus && flags.width > len)
	{
		if (flags.negative == 1)
			ft_putchar('-');
		if (flags.dot && zero > 0)
		{
			while (zero)
			{
				ft_putchar('0');
				zero--;
			}
		}
		ft_putstr(charg);
		while (space > 0)
		{
			ft_putchar(' ');
			space--;
		}
	}
	else //08.5 34
	{
		if (!flags.zero)
		{
			// printf("\ncheck--0\n");
			while (space > 0)
			{
				ft_putchar(' ');
				space--;
			}
		}
		else if (flags.zero && !flags.minus && flags.prec && !flags.negative && flags.width)
		{
			// printf("\ncheck--3\n");
			space = flags.width - flags.prec;
			zero = flags.prec - len;
			while (space > 0)
			{
				ft_putchar(' ');
				space--;
			}
			while (zero > 0)
			{
				ft_putchar('0');
				zero--;
			}
		}
		else if (flags.zero && flags.minus)
		{
			// printf("\ncheck--2\n");
			// space = flags.width - flags.prec;
			if (flags.negative)
				space--;
			zero = flags.width - len;
			if (flags.negative)
				zero = flags.width - space - 4;
			// printf("\nspace --- %d\n", space);
			// while (space > 0)
			// {
			// 	ft_putchar(' ');
			// 	space--;
			// }
			while (zero > 0)
			{
				ft_putchar('0');
				zero--;
			}
		}
		if (flags.negative && !(flags.dot && flags.zero && flags.negative && flags.width && !flags.minus))
			ft_putchar('-');
		if (flags.dot || flags.zero) // 010.5 -216
		{
			if (flags.dot && flags.zero && flags.negative && flags.width && !flags.minus)
			{
				space = flags.width - flags.prec - 1;
				zero = flags.prec - len + 1;
				while (space > 0)
				{
					ft_putchar(' ');
					space--;
				}
				if (flags.negative)
				{
					ft_putchar('-');
					flags.negative = 0;
				}
			}
			// printf("\ncheck--1\n");
			while (zero > 0)
			{
				ft_putchar('0');
				zero--;
			}
		}
		ft_putstr(charg);
	}
	
	free(charg);
}

void     ft_check_flags(const char *format)
{
	while (!(*format >= '1' && *format <= '9'))
	{
		if (*format == '-' || *format == '0')
		{
			(*format == '-') ? flags.minus = 1 : 0;
			(*format == '0') ? flags.zero = 1 : 0;
		}
		else if (*format != '-' || *format != '0')
		if (*format == '.')
			flags.dot = 1;
		if (*format == '*')
			flags.star = 1;
		(*format == '.') ? flags.dot = 1 : 0;
		(*format == '*') ? flags.star = 1 : 0;
		format++;
	}
}

void	ft_printf2(char *print)
{
	while (*print)
	{
		// make_zeros();
		if (*print == '%')
		{
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
				if (flags.minus && flags.zero)
					flags.zero = 0;
				print++;
			}
			if (*print == '*')
			{
				flags.width = va_arg(flags.list, int);
				if (flags.width < 0)
					{
						flags.minus = 1;
						flags.width *= (-1);
					}
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
					flags.prec = va_arg(flags.list, int);
					if (flags.prec < 0)
						flags.prec = 0;
					print++;
				}
				else if (*print >= '0' && *print <= '9')
				{
					flags.prec = ft_atoi(print);
					while (*print >= '0' && *print <= '9')
						print++;
				}
			}
			// if (*print != '%')
			// 	flags.arg = va_arg(flags.list, int);
			// printf("widht -- %d\n", flags.width);
			// printf("prec -- %d", flags.prec);
			ft_check_convs(print);
			print++;
			continue;
		}
		ft_putchar(*print);
		print++;
	}
}


int		ft_printf(const char *format, ...)
{
	char *print;

	// t_flags	flags;

	va_start(flags.list, format);
	print = (char *)format;
    make_zeros();
    ft_printf2(print);
	va_end(flags.list);
	return (flags.count);	
}


// int	main()
// {
// 	// int a = 10;
	
// 	ft_printf("%d\n", 3);
// 	printf("%d\n", 3);
// }