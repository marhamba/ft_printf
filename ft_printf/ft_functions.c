#include "ft_printf.h"

void	ft_treat_decimal()
{
	char	*charg;
	int		len;
	int		space;
	int		zero;
	int		arg;

	arg = va_arg(flags.list, int);
	if (!(charg = malloc(sizeof(ft_strlen(ft_itoa(arg))))))
		return ;
	charg = ft_itoa(arg);
	len = ft_strlen(charg);
	printf("%d\n %d\n", flags.width, flags.prec);
	zero = flags.prec - len;
	space = flags.width - flags.prec;
	if (flags.minus == 0)
	{
		ft_notminus_cases(len, space, zero, charg);
	}

}

void    ft_print_case1(int space, int zero, char *charg)
{
    while (space)
    {
        ft_putchar(' ');
        space--;
    }
    while (zero)
    {
        ft_putchar('0');
        zero--;
    }
    ft_putstr(charg);
}

void    ft_notminus_cases(int len, int space, int zero, char *charg)
{
    if (flags.prec)
        flags.zero = 0;
    if (flags.width > flags.prec && flags.width > len)
        ft_print_case1(space, zero, charg); 
}