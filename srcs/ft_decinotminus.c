#include "ft_printf.h"

void    ft_notminus_cases(int len, int space, unsigned int zero, char **charg, char *print)
{
	printf("charg --- %s\n", *charg);
    // if (flags.prec)
    //     flags.zero = 0;
    if (flags.width > flags.prec && flags.width > len && flags.prec > len)
        ft_printdec_case1(space, zero, charg);
	else if ((flags.width > len && flags.prec < len && flags.width > flags.prec)
		|| (flags.prec == len && flags.prec < flags.width))
		ft_printdec_case2(len, space, charg);
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
			if (flags.width == flags.prec && len == 1)
			{
				if (flags.width == 0 && flags.prec == 0)
				{
					if (*charg[0] == '0')
					{
						int i;
						 i = 0;
						 if (print[i] == '%' && print[i + 1] == 'd')
							ft_putchar('0');
						else
							return ;
					}
				}
			}
			else
				ft_printdec_case4(charg);
		}
	// free(*charg);
}

void    ft_printdec_case1(int space, unsigned int zero, char **charg)
{
    while (space > 0)
    {
        ft_putchar(' ');
        space--;
    }
	if (flags.negative == 1)
		ft_putchar('-');
    while (zero > 0)
    {
        ft_putchar('0');
        zero--;
    }
	ft_putstr(*charg);
	// free(*charg);
}

void	ft_printdec_case2(int len, int space, char **charg)
{
	flags.prec = 0;
	space = flags.width - len;
	while(space)
	{
		ft_putchar(' ');
		space--;
	}
	if (flags.negative == 1)
		ft_putchar('-');
	ft_putstr(*charg);
	// free(*charg);
}

void	ft_printdec_case3(int len, unsigned int zero, char **charg)
{
	zero = flags.prec - len;
	if (flags.negative == 1)
		ft_putchar('-');
	while (zero)
	{
		ft_putchar('0');
		zero--;
	}
	ft_putstr(*charg);
	// free(*charg);
}

void	ft_printdec_case4(char **charg)
{
	if (flags.negative == 1)
		ft_putchar('-');
	ft_putstr(*charg);
	// free(*charg);
}