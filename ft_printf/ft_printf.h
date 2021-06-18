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
	unsigned int		zero;
	int		minus;
	int		star;
	int		dot;
	int		count;
	void	*print;
	va_list	list;
	int		arg;
	int		negative;
}					t_flags;

t_flags	flags;

int			ft_printf(const char *format, ...);
t_flags		make_zeros(t_flags flags);
void		ft_check_format(char *format);
void		ft_check_convs(char *format);
void		print_minus1(int space, char *charg);
void		print_minus0(int space, char *charg);
void		ft_minus_cases(int	len, int space, unsigned int zero, char *charg);
void		ft_notminus_cases(int len, int space, unsigned int zero, char **charg);
void		ft_treat_decimal();
void		ft_check_flags(const char *format);
void		ft_printf2(char *print);
int			ft_dot_function(char *format);
void    	ft_printdec_case1(int space, unsigned int zero, char **charg);
void		ft_printdec_case2(int len, int space, char **charg);
void		ft_printdec_case3_and6(int len, unsigned int zero, char **charg);
void		ft_printdec_case4_and5(char **charg);

#endif

