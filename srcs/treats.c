#include "ft_printf.h"

void	ft_treat_decimal(int mek)
{
	char	*charg;

	mek = 0;
	charg = ft_itoa(g_flags.arg);
	ft_putstr(charg);
	free(charg);
}

void	ft_treat_unsigned(int mek)
{
	char	*str;

	mek = 0;
	g_flags.point = va_arg(g_flags.list, unsigned int);
	str = ft_itoa(g_flags.point);
	ft_putstr(str);
	free(str);
}

void	ft_treat_pointer(int mek)
{
	char			*str;
	unsigned long	arg;

	mek = 0;
	g_flags.point = va_arg(g_flags.list, unsigned long);
	ft_putstr("0x");
	arg = g_flags.point;
	if (arg == 0)
	{
		ft_putchar('0');
		return ;
	}
	str = ft_dectohex_long(arg);
	ft_putstr(str);
	free(str);
}

void	ft_treat_hexa(int mek)
{
	char			*str;
	unsigned int	arg;

	mek = 0;
	g_flags.unarg = va_arg(g_flags.list, unsigned int);
	arg = g_flags.unarg;
	if (arg == 0)
	{
		ft_putchar('0');
		return ;
	}
	str = ft_dectohex(arg);
	ft_putstr(str);
	free(str);
}
