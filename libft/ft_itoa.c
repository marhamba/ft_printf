/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:29:07 by marhamba          #+#    #+#             */
/*   Updated: 2021/07/23 11:29:06 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	if (num == 0)
		len++;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(long n)
{
	int		lenght;
	char	*str;
	int		i;
	long	num;

	num = n;
	lenght = ft_len(num);
	str = (char *)malloc(sizeof(char) * lenght + 1);
	if (!str)
		return (NULL);
	i = 0;
	str = chgitem(lenght, str, i, num);
	return (str);
}

char	*chgitem(int	lenght, char *str, int i, long num)
{
	if (num < 0)
	{
		str[i] = '-';
		num *= -1;
	}
	i = lenght - 1;
	if (num == 0)
		str[i] = '0';
	while (num > 0)
	{
		str[i--] = num % 10 + 48;
		num /= 10;
	}
	str[lenght] = '\0';
	return (str);
}
