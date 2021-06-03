#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include  "libft.h"
#include <stdarg.h>


typedef struct		s_flags
{
	int		width;
	int		prec;
	int		zero;
	int		minus;
	int		star;
	int		dot;
	int		count;
	void	*print;
	va_list	list;
}					t_flags;

t_flags	flags;

int			ft_printf(const char *format, ...);
t_flags		make_zeros(t_flags flags);
int			ft_check_format(char **format);
void		ft_check_convs(char **format);
void		print_minus1(int space, char *charg);
void		print_minus0(int space, char *charg);
void		ft_minus_cases(int	len, int space, char *charg);
void		notminus_cases(int len, int space, char *charg);
void		ft_treat_decimal();
void		ft_check_flags(const char *format);

#endif

