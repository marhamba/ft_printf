#include "ft_printf.h"

void	ft_treat_char()
{
	int		space;
	int		printed;

	printed = 0;
	if (flags.width > 0 && !flags.minus)
	{
		space = flags.width - 1;
		while (space > 0)
		{
			ft_putchar(' ');
			space--;
		}
		if (flags.negative)
			ft_putchar('-');
		if (printed == 0)
		{
			ft_putchar(flags.arg);
			printed = 1;
		}
	}
	if (flags.minus && flags.width)
	{
		space = flags.width - 1;
		if (flags.negative)
			ft_putchar('-');
		if (printed == 0)
		{
			ft_putchar(flags.arg);
			printed = 1;
		}
		while (space > 0)
		{
			ft_putchar(' ');
			space--;
		}
	}
	else if ((flags.width == 0 && flags.minus == 0 && printed == 0)
		|| (!flags.width && flags.minus && printed == 0))
	{
		ft_putchar(flags.arg);
		printed = 1;
	}
	
}

void	ft_treat_unsigned()
{
	char *str;

	flags.uarg = va_arg(flags.list, long);
	str = ft_itoa(flags.uarg);
	if (str[0] == '-' && flags.uarg != LONG_MIN)
	{
		flags.uarg *= (-1);
		flags.uarg = UINT_MAX - flags.uarg + 1;
		free(str);
		str = ft_itoa(flags.uarg);	
	}
	else if (flags.uarg == LONG_MAX)
	{
		free(str);
		str = ft_itoa(UINT_MAX);
	}
	else if (flags.uarg == LONG_MIN)
	{
		free(str);
		str = ft_itoa(0);
	}
	ft_putstr(str);
	free(str);
}

void	ft_treat_string(char *format)
{
	int	space;
	int	len;

	len = ft_strlen(flags.string);
	if (flags.width > flags.prec && flags.prec != 0)
	{
		space = flags.width - flags.prec;
		len = flags.width - space;
	}
	else if (flags.width == 0 && flags.prec == 0)
		space = 0;
	else if (!flags.width && flags.dot && flags.isprec == 0)
		return ;
	else if (flags.width < flags.prec && flags.prec < len)
	{
		len = flags.prec;
		space = 0;
	}
	if (flags.prec == 0 && flags.dot == 0 && flags.width && flags.isprec == 0)
	{
		space = flags.width - len;
		len = ft_strlen(flags.string);
	}
	else if (flags.width > flags.prec && flags.prec == 0)
	{
		len = 0;
		space = flags.width;
	}
	if (flags.minus)
	{
		while (len > 0)
		{
			ft_putchar(*flags.string);
			len--;
			flags.string++;
		}
	}
	while (space > 0)
	{
		ft_putchar(' ');
		space--;
	}
	if (!flags.minus)
	{
		while (len > 0)
		{
			ft_putchar(*flags.string);
			len--;
			flags.string++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	char *print;

	flags.count = 0;
	va_start(flags.list, format);
	print = (char *)format;
    ft_printf2(print);
	va_end(flags.list);
	return (flags.count);	
}