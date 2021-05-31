/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:52:07 by marhamba          #+#    #+#             */
/*   Updated: 2021/05/30 22:11:51 by marhamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_eval_format(t_print *tab, const chhar *format, int pos)
{
	while (!(ft_isalpha(format[pos]) || format[pos] == '%'))
	{
		if (format[pos] == ' ')
			pos = ft_space(tab, pos);
		if (format[pos] == '0')
			pos = ft_eval_zero(tab, format, pos);
		if (format[pos] == '*')
			pos = ft_eval_star(tab, format, pos);
		if (format[pos] == '-')
			pos = ft_eval_dash(tab, format, pos);
		if (format[pos] == '.')
			pos = ft_eval_precision(tab, format, pos);
		if (ft_isdigit(format[pos]))
			pos = ft_eval_width(tab, format, pos);
	}
	ft_eval_variable(tab, format, pos);
	ft_reset_tab(tab);
	return (pos);
}


int		ft_eval_variable(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_output_char(tab);
	else if (format[pos] == 's')
		ft_output_string(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_output_int(tab);
	else if (format[pos] == 'u')
		ft_output_unsigned_int(tab);
	else if (format[pos] == 'p')
		ft_output_pointer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		ft_output_hexa(tab, format[pos] - 23);
	else if (format[pos] == '%')
		ft_percentage(tab);
	return (pos);
}
