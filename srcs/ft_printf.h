/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:15:10 by tumolabs          #+#    #+#             */
/*   Updated: 2021/07/23 19:01:24 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include  "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int				count;
	va_list			list;
	int				arg;
	char			*string;
	unsigned long	point;
	int				areg;
	unsigned int	unarg;
	int				unsignedd;
}				t_flags;

t_flags	g_flags;

int			ft_printf(const char *format, ...);
void		make_zeros(int mek);
void		ft_check_convs(char *format);
void		ft_treat_decimal(int mek);
void		ft_printf2(char *print);
void		ft_treat_pointer(int mek);
void		ft_treat_unsigned(int mek);
void		ft_treat_hexa(int mek);
char		*ft_dectohex(unsigned int arg);
char		*ft_dectohex_long(unsigned long arg);
char		*cont1(char *str, int count, unsigned long mod);
char		*cont2(char *str, int count, unsigned int mod);
void		ft_check_convs2(char *format);

#endif
