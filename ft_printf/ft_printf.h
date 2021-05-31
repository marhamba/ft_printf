#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct		s_flags
{
	int		width;
	int		zero;
	int		minus;
	int		star;
	int		dot;
	void	*print;
	va_list	args;
}					t_flags;

t_list	flags;
va_list list;

int		ft_printf(const char *format, ...);
