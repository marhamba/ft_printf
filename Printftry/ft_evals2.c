/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:04:17 by marhamba          #+#    #+#             */
/*   Updated: 2021/05/30 22:11:49 by marhamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_space(t_print *tab, int pos)
{
	pos++;
	tab->sp = 1;
	return (pos);
}

int		ft_eval_zero(t_print *tab, const char *format, int pos)
{
	int i;

	i = 0;
	pos++;
	tab.zero = 1;
	while (format[pos] == '0')
		pos++;
	if (ft_isdigit(format(pos)))
	{
		i = ft_atoi(&format[pos]);
		pos += ft_numlen(i);
	}
	tab.width = 1;
	return (pos);
}

int		ft_eval_star(t_print *tab, const char *format, int pos)
{
	pos++;
	if (!tab->pnt)
	{
		tab.width = va_arg(tab->args, int);
		ft_check_width(tab);
	}
	else
	{
		tab->prc = va_arg(tab->args, int);
		ft_check_precision(tab);
	}
	if (format[pos] == '.')
		pos = ft_eval_precision(tab, format, pos);
	if (format[pos] == '*')
		pos = ft_eval_star(tab, format, pos);
	while (format[pos] == '*')
		pos++;
	return (pos);
}


int		ft_eval_dash(t_print *tab, const char *format, int pos)
{
	pos++;
	if (tab->dash == 1)
	{
		while (format[pos] == '-' || format[pos] == '0')
			pos++;
		return (pos);
	}
	tab->dash = 1;
	tab->zero = 0;
	while (format[pos] == '')
}
