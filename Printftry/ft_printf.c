/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:44:06 by marhamba          #+#    #+#             */
/*   Updated: 2021/05/30 20:02:48 by marhamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_making_zeros(t_print *tab)
{
	tab.width = 0;
	tab.prc = 0;
	tab.zero = 0;
	tab.pnt = 0;
	tab.sign = 0;
	tab.tl = 0;
	tab.is_zero = 0;
	tab.dash = 0;
	tab.perc = 0;
	tab.sp = 0;
	return (tab);
}

int		ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		r;

	if (!format)
		return (0);
	r = 0;
	if (!(tab = malloc(sizeof(t_print))))
		return (-1);
	ft_making_zeros(tab);
	i = -1;
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			r += write(1, &format[i], 1);
	}
	r += tab.tl;
	va_end(tab->args);
	free(tab);
	return (r);
}
