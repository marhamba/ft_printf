/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:59:59 by marhamba          #+#    #+#             */
/*   Updated: 2021/07/23 11:30:16 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../srcs/ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char			*ft_itoa(long n);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*chgitem(int lenght, char *str, int i, long	num);
#endif
