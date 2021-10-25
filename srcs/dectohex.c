/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:24:38 by tumolabs          #+#    #+#             */
/*   Updated: 2021/07/23 18:45:53 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dectohex_long(unsigned long arg)
{
	char			*str;
	unsigned long	mod;
	int				count;

	count = 0;
	mod = 0;
	while (arg)
	{
		arg /= 16;
		count++;
	}
	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	count -= 1;
	str = cont1(str, count, mod);
	return (str);
}

char	*cont1(char *str, int count, unsigned long mod)
{
	while (g_flags.point)
	{
		mod = g_flags.point % 16;
		g_flags.point /= 16;
		if (mod > 9)
		{
			if (g_flags.areg == 1)
				mod += 55;
			else
				mod += 87;
		}
		else
			mod += 48;
		str[count] = mod;
		count--;
	}
	return (str);
}

char	*ft_dectohex(unsigned int arg)
{
	char			*str;
	unsigned int	mod;
	int				count;

	count = 0;
	mod = 0;
	while (arg)
	{
		arg /= 16;
		count++;
	}
	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	count -= 1;
	str = cont2(str, count, mod);
	return (str);
}

char	*cont2(char *str, int count, unsigned int mod)
{
	while (g_flags.unarg)
	{
		mod = g_flags.unarg % 16;
		g_flags.unarg /= 16;
		if (mod > 9)
		{
			if (g_flags.areg == 1)
				mod += 55;
			else
				mod += 87;
		}
		else
			mod += 48;
		str[count] = mod;
		count--;
	}
	return (str);
}
