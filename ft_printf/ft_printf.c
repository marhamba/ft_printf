#include "ft_printf.h"


t_flags     make_zeros(t_flags flags)
{
    flags.width = 0;
    flags.minus = 0;
    flags.dot = -1;
    flags.prec = 0;
    flags.star = 0;
	flags.arg = 0;
	flags.count = 0;
	flags.zero = 0;
    return (flags);
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
			ft_treat_decimal();
		}
}

void	ft_treat_decimal()
{
	char	*charg;
	int		len;
	int		space;
	unsigned int		zero;
	int	a;

	a = ft_strlen(ft_itoa(flags.arg)) + 1;
	flags.arg = va_arg(flags.list, int);
	if (!(charg = malloc(a)))
	{
		printf("kashmar");
		return ;
	}
	else
		printf("chkashmar");
	charg[a] = '\0';
	charg = ft_itoa(flags.arg);
	// printf("%s%s\n", "---charg", charg);
	len = ft_strlen(charg);
	zero = flags.prec - len;
	space = flags.width - flags.prec;
	if (flags.minus == 0)
	{
		ft_notminus_cases(len, space, &charg);
	}

}

void    ft_printdec_case1(int len, int space, char **charg)
{
    while (space > 0)
    {
        ft_putchar(' ');
        space--;
    }
    // while (zero > 0)
    // {
    //     ft_putchar('0');
    //     zero--;
    // }
    while (len > 0)
	{
		ft_putchar(**charg);
		len--;
	}
	free(*charg);
	printf("%s%d", *charg, 3);
}

void	ft_printdec_case2(int len, int space, char **charg)
{
	flags.prec = 0;
	space = flags.width - len;
	printf("%d", space);
	while(space)
	{
		ft_putchar(' ');
		space--;
	}
	while(len)
	{
		ft_putchar(**charg);
		len--;
	}
	free(charg);
}

void    ft_notminus_cases(int len, int space, char **charg) // avelacnel int zero
{
    if (flags.prec)
        flags.zero = 0;
    if (flags.width > flags.prec && flags.width > len)
        ft_printdec_case1(len, space, charg); 
	if (flags.width > len && flags.prec < len)
		ft_printdec_case2(len, space, charg);
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
	va_list	list;
	while (*print)
	{
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
				flags.width = va_arg(list, int);
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
					print++;
				}
				else if (*print >= '0' && *print <= '9')
				{
					flags.prec = ft_atoi(print);
					while (*print >= '0' && *print <= '9')
						print++;
				}
			}
			if (*print != '%')
				flags.print = va_arg(list, void *);
			ft_check_convs(print);
			print++;
		}
		ft_putchar(*print);
		print++;
	}
}


int		ft_printf(const char *format, ...)
{
	int pos;
	char *print;

	va_start(flags.list, format);
	print = (char *)format;
    pos = 0;
    make_zeros(flags);
    ft_printf2(print);
	va_end(flags.list);
	return (flags.count);	
}


int	main()
{
	ft_printf("%7.3d\n", 12345);
}