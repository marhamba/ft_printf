/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:15:31 by marhamba          #+#    #+#             */
/*   Updated: 2021/06/03 19:11:01 by marhamba         ###   ########.fr       */
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
	printf("%d\n", flags.prec);
}

int		ft_dot_function(char *format)
{
	if (*format == '.')
		format++;
	printf("%s", "check--format_if3-dot\n");
	// printf("%s", format);
	printf("%d\n", flags.prec);
	if (*format == '*')
	{
		printf("%s", "--if");
		flags.prec = va_arg(flags.list, int);
	}
	else if (*format >= '0' && *format <= '9')
	{
		printf("%s", "--else");
		flags.prec = ft_atoi(format);
	}
	printf("%d\n", flags.prec);
	format++;
	ft_check_convs(format);
	return (0);
}

//d-i hamar flager stugel
void     ft_check_format(char *format)
{
	// char	*len;
	printf("%s", "check---format1\n");
    // format++;
	if (*format == '%')
		format++;
	if (*format == '*')
    {
		printf("%s", "check--format-elseif3*\n");
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
	// else
	// {
		// while (*format >= '0' && *format <= '9')
		// {
		// 	printf("%s", "if-check---format_if2\n");
		// 	if (*format >= '0' && *format <= '9')
		// 	{
		// 		flags.width = ft_atoi(format);
		// 		len = ft_itoa(flags.width);
		// 		printf("%d\n", flags.width);
		// 		continue ;
		// 	}
		// }
		// while (*format >= '0' && *format <= '9')
		// {
		// 	while(len)
		// 	{
		// 		if(*format == '.')
		// 			ft_dot_function(format);
		// 		format++;
		// 		len--;
		// 	}
		// 	format++;
		// }
		// if(*format == '.')
		// 	ft_dot_function(format);
	// }
}

void	ft_check_convs(char *format)
{
	printf("%s", "check_convsss\n");
	// while (*format != 'd' || *format != 'i')
	// {
		// format++;
		if (*format == 'd' || *format == 'i')
		{
			printf("%s\n", "decimal check");
			ft_treat_decimal();
			printf("%s\n", "blaba");
		}
		// format++;
		printf("%s\n", "angam--");
	// }
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
	{
		ft_putchar('0');
		flags.zero--;
	}
	ft_putstr(charg);
	while (space)
	{
		ft_putchar(' ');
		space--;
	}
}

void	print_minus0(int	space, char *charg)
{
	while (space)
	{
		ft_putchar(' ');
		space--;
	}
	while (flags.zero)
	{
		ft_putchar('0');
		flags.zero--;
	}
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

	arg = va_arg(flags.list, int);
	space = flags.width - 1;
	flags.prec = 0;
	//if (flags.width > 0)
}

void		ft_treat_decimal()
{
	printf("\n%s", "decimal--1");
	int		arg; //va_argic vercracy tiv
	int		len;
	char	*charg; //argi char sarqac tesaky
	int		space;

	arg = va_arg(flags.list, int);
	if (!(charg = malloc(100))) 
		return ;
	charg = ft_itoa(arg);
	len = ft_strlen(charg);
	flags.zero -= len;
	space = flags.width - flags.prec;
	if (flags.minus == 0)
		ft_minus_cases(len, space, charg);
	else
		ft_notminus_cases(len, space, charg);
	free(charg);
}


void     ft_check_flags(const char *format)
{
	// printf("%s", "check---flags\n");
	while (!(*format >= '1' && *format <= '9'))
	{
		// printf("%s", "check_____flagswhile\n");
		if (*format == '-' || *format == '0')
		{
			// printf("%s", "check___flaaaaagsif\n\n");
			(*format == '-') ? flags.minus = 1 : 0;
			(*format == '0') ? flags.zero = 1 : 0;
		}
		else if (*format != '-' || *format != '0')
			// printf("%s\n", "if--chi--mtnum");
		if (*format == '.')
			flags.dot = 1;
		if (*format == '*')
			flags.star = 1;
		(*format == '.') ? flags.dot = 1 : 0;
		(*format == '*') ? flags.star = 1 : 0;
		// printf("%d\n", flags.dot);
		format++;
		// printf("%d\n", flags.star);
	}
	// ft_check_format(format);
}

void	ft_printf2(char *print)
{
	while (*print)
	{
	//	printf("%s", "while\n");
		if (*print == '%')
		{
			// printf("%s", "if\n");
			// ft_check_flags(print);
			// ft_check_format(print);
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
				flags.width = va_arg(flags.list, int);
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
				flags.prec = va_arg(flags.list, int);
				else if (*print >= '0' && *print <= '9')
				{
					flags.prec = ft_atoi(print);
					while (*print >= '0' && *print <= '9')
						print++;
				}
			}
			if (*print != '%')
				flags.print = va_arg(flags.list, void *);
			ft_check_convs(print);
			print++;
		}
		ft_putchar(*print);
		print++;
	}
// 	if (*format == '%')
// 	{
// 	//	printf("%s", "if\n");
// 		ft_check_flags(format);
// 		ft_check_format(print);
// 	}
// //	(*format == '%') ? ft_check_flags(&format) : ft_check_format(&print);
// 	if (*format && *format != '%')
// 		write (1, &format, 1);
}


int		ft_printf(const char *format, ...)
{
	int pos;
	char *print;
	// va_list	list;

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
	ft_printf("hello %-015.20d\n", 12);
	//ft_printf("%d", flags.count);
}
