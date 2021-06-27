#include "ft_printf.h"

void	ft_minus_cases(int len, int space, unsigned int zero, char **charg)
{
	if (flags.width > flags.prec && flags.width > len && flags.prec > len)
        ft_printdec_case5(space, zero, charg);
	else if ((flags.width > len && flags.prec < len && flags.width > flags.prec)
		|| (flags.prec == len && flags.prec < flags.width))
		ft_printdec_case6(len, space, charg);
	else if ((flags.width < flags.prec && flags.prec > len && flags.width > len)
		|| (flags.width < flags.prec && flags.prec > len && flags.width < len)
		|| (flags.width == len && flags.prec > len)
		|| (flags.width == flags.prec && len < flags.width))
			ft_printdec_case3(len, zero, charg);
	else if ((flags.width > flags.prec && len > flags.width && flags.prec < len)
		|| (flags.width < flags.prec && flags.width < len && len > flags.prec)
		|| (flags.width == flags.prec && flags.prec == len)
		|| (flags.width == flags.prec && len > flags.width)
		|| (flags.width == len && flags.prec < len)
		|| (flags.prec == len && flags.width < len))
		{
			// printf("test1\n");
			if (flags.width == flags.prec && len > flags.width)
			{
				if (flags.width == 0 && flags.prec == 0)
				{
					if (flags.arg == '0')
					{
						// printf("test");
						return ;
					}
				}
			}
			else
				ft_printdec_case4(charg);
		}
	// free(*charg);
}

void	ft_printdec_case5(int space, unsigned int zero, char **charg)
{
	if (flags.negative == 1)
		ft_putchar('-');
    while (zero > 0)
    {
        ft_putchar('0');
        zero--;
    }
	ft_putstr(*charg);
	while (space > 0)
    {
        ft_putchar(' ');
        space--;
    }
	// free(*charg);
}

void	ft_printdec_case6(int len, unsigned int space, char **charg)
{
	if (flags.negative == 1)
		ft_putchar('-');
	ft_putstr(*charg);
	space = flags.width - len;
	while(space)
	{
		ft_putchar(' ');
		space--;
	}
	// free(*charg);
}