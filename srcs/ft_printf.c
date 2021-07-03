#include "ft_printf.h"

void	ft_treat_char()
{
	// int space;

	flags.arg = va_arg(flags.list, int);
	// if (flags.prec != 0 && flags.dot != 0)
	// 	return ;
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
	// printf("arg-- %d", flags.arg);
	char	*charg;
	int		len;
	int		space;
	int		zero;
	unsigned int	argument;
	// int		zp;
	
	// zp = 0;
	printf("\nminus --- %d\n", flags.minus);
	argument = (unsigned int)flags.arg;
	flags.pz = 1;
	(void)print;
	if (flags.width < 0)
	{
		// printf("barev");
		flags.width *= -1;
		flags.minus = 1;
		flags.zero = 0;
	}
	// if (flags.arg < 0 && flags.width < 0)
	// 	flags.minus = 0;
	if (flags.arg < 0)
	{
		flags.negative = 1;
		flags.arg = flags.arg * (-1);
	}
	charg = ft_itoa(flags.arg);
	len = ft_strlen(charg);
	// printf("width --- %d\n", flags.width);
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
	// printf("zero is --- %d\n", zero);
	space = flags.width - len;
	if (flags.dot && flags.prec > len)
		space -= zero;
	if (flags.minus && flags.width > len)
	{
		// if (flags.arg == 0)
		// {
		// 	if ((flags.width > flags.prec && flags.prec > len) || (flags.width == flags.prec))
		// 		flags.pz = 1;
		// }
		if (flags.negative == 1 && flags.arg != INT_MIN)
			ft_putchar('-');
		if ((flags.isprec == 0 && flags.width && flags.arg == 0 && flags.dot && flags.prec == 0)
			|| (flags.width && flags.arg == 0 && flags.dot && flags.prec == 0))
		{
				flags.pz = 0; 
				space += 1;
				while (space > 0)
				{
					ft_putchar(' ');
					space--;
				}
		}
		if (flags.dot && zero > 0 && !(flags.width && flags.prec && flags.arg == 1))
		{
			// space = flags.width - len;
			// printf("hello");	
			while (zero)
			{
				// printf("\nzero---\n")
				ft_putchar('0');
				zero--;
			}
		}
		// if(flags.width > 0 && flags.zero && flags.arg > 0 && flags.prec > 0 && flags.star == 1)
		if (flags.width && flags.prec && flags.arg == INT_MIN)
		{
			space += 1;
			flags.arg *= (-1);
			flags.minus = 0;
		}
		// if (flags.width && flags.prec && flags.arg == 1)
		// {

		// 	printf("barev");
		// 	// printf("barev");
		// 	flags.minus = 0;
			
		// 		// space = flags.width - flags.prec;
		// 	// printf("\n%d\n", space);
		// }
		// printf("check %d\n", flags.prec);
		// if (flags.pz && flags.prec)
		// {
		// 	printf("Hello\n");
		// 	ft_putstr(charg);
		// }

		if (flags.minus)
		{
			// printf("barev");
			// printf("barev");
			while (zero > 0)
			{
				ft_putchar('0');
				zero--;
			}
			if (flags.pz)
				ft_putstr(charg);
			if (flags.width > flags.prec && flags.arg > 0)
				space = flags.width - len;
			if (flags.width > flags.prec && flags.prec > len && flags.arg != 0)
				space -= 1;
			while (space > 0)
			{
				ft_putchar(' ');
				space--;
			}
		}
		if (!flags.minus)
		{
			while (space > 0)
			{
				ft_putchar(' ');
				space--;
			}
		}
		if (flags.width && flags.prec && flags.arg == 1 && !flags.minus)
		{
			// printf()
			while (zero > 0)
			{
				ft_putchar('0');
				zero--;
			}
		}
		if (!flags.minus)
		{
			if (flags.pz)
				ft_putstr(charg);
		}
			// printf("\ncheck --- \n");
	}
	else
	{
		
		// if (flags.dot && flags.zero)
		// 	flags.zero = 0;
			// printf("arg is --- %d\n\n", flags.arg);

		// if (flags.arg == 0)
		// {
		// 	if ((flags.dot && flags.prec > len && flags.minus)
		// 		|| (flags.width == flags.prec && flags.width == len)
		// 		|| (flags.width == flags.prec && flags.prec > len)
		// 		|| (flags.width == len && flags.prec > len)
		// 		|| (flags.width > len) || (flags.width > len && flags.minus)
		// 		|| (flags.width > len && flags.zero))
		// 		flags.pz = 1;
		// }
		if (flags.width == 0 && flags.prec == 0 && flags.arg == 0 && flags.star && flags.dot)
			flags.pz = 1;
		else if (flags.width == 0 && flags.dot && flags.isprec == 0 && flags.arg == 0 && flags.prec == 0)
			return ;
		else if (flags.arg == 0 && flags.isprec == 0 && (flags.width == 0 || flags.width > 0 || (flags.zero && flags.width > 0)))
				flags.arg = 0;
		else if ((flags.prec == 0 && flags.arg == 0 && flags.isprec == 0) ||  (flags.prec == 0 && flags.arg == 0 && flags.width == 0))
			return ;
		else if (flags.width && flags.prec == 0 && flags.isprec == 1 && flags.arg == 0)
		{
			space = flags.width < 0 ? flags.width * -1 : flags.width;
			flags.pz = 0;
			while (space > 0)
			{
				ft_putchar(' ');
				space--;
			}
		}
		// if (flags.arg == 0)
		// {
		// if ((flags.width < flags.prec && flags.width > len && flags.arg == 0)
		// 	|| (flags.dot && flags.arg == 0) || (flags.prec = 0 && flags.isprec && flags.arg == 0)
		// 	||(flags.zero && flags.prec == 0 && flags.isprec && flags.width > flags.prec && flags.prec < len && flags.arg == 0)
		// 	|| (flags.width == len && flags.dot && flags.arg == 0)
		// 	|| (flags.width > len && flags.dot && flags.arg == 0)
		// 	|| (flags.minus && flags.width > len && flags.dot && flags.arg == 0))
		// 		flags.pz = 0;
		// }
		// if (flags.arg == 0 && flags.prec == 0 && flags.isprec == 1 && flags.width > 0 && flags.prec < len)
		// 	flags.pz = 0;
		if (!flags.zero)
		{
			// printf("\ncheck---\n");
			if (flags.width && flags.isprec == 0 && flags.arg == 0 && flags.pz == 0)
				space += 1;
			while (space > 0)
			{
				ft_putchar(' ');
				space--;
			}
		}
		else if (flags.zero && !flags.minus && flags.prec && !flags.negative && flags.width)
		{
			space = flags.width - flags.prec;
			zero = flags.prec - len;
			if (flags.prec < len)
				space -= 1;
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
			if (flags.negative)
				space--;
			zero = flags.width - len;
			if (flags.negative)
				zero = flags.width - space - 4;
			while (zero > 0)
			{
				ft_putchar('0');
				zero--;
			}
		}
		if (flags.negative && !(flags.dot && flags.zero && flags.negative && flags.width && !flags.minus))
			ft_putchar('-');
		if (flags.dot || flags.zero)
		{
			if (flags.dot && flags.zero)
			{
				// printf("\n%d\n", flags.arg);
				flags.zero = 0;
				space = zero;
				zero = 0;
				while (space > 0)
				{
					ft_putchar(' ');
					space--;
				}
				if (flags.negative)
					ft_putchar('-');
			}
			if (flags.isprec == 0 && flags.width && flags.arg == 0 && flags.dot && flags.prec == 0)
			{
				flags.pz = 0;
				space += 1;
				while (space > 0)
				{
					ft_putchar(' ');
					space--;
				}
			}
			if (flags.dot && flags.zero && flags.negative && flags.width && !flags.minus)
			{
				space = flags.width - flags.prec - 1;
				zero = flags.prec - len + 1;
				if (flags.prec && flags.prec < len && flags.negative)
					space -= 1;
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
			// if (flags.zero)
			// {
			// printf("check %d\n\n", flags.arg);
				while (zero > 0)
				{
					// printf("barev");
					ft_putchar('0');
					zero--;
				}
			// }
		}
		// printf("\n\n\n%d\n\n\n", flags.pz);
		// printf("\narg --- %d\n", flags.arg);
		if (flags.pz)
			ft_putstr(charg);
		// else if (flags.arg > INT_MAX)
		// {
		// 	// printf("barev");
		// 	ft_putstr("-1");
		// }
		// if (flags.pz && flags.prec)
		// {
		// 	printf("World\n");
		// 	ft_putstr(charg);
		// }
	}
	
	free(charg);
}

int		ft_printf(const char *format, ...)
{
	char *print;

	va_start(flags.list, format);
	print = (char *)format;
    // make_zeros();
    ft_printf2(print);
	va_end(flags.list);
	// printf("%d", flags.minus);
	return (flags.count);	
}