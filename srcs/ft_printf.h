#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include  "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>


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
	int		arg;
	int		negative;
	int		r;
	int		minusn;
	char	argc;
	int		isprec;
	int		pz;
	char	*string;
}					t_flags;

t_flags	flags;

int			ft_printf(const char *format, ...);
void		make_zeros();
void		ft_check_format(char *format);
void		ft_check_convs(char *format);
void		print_minus1(int space, char *charg);
void		print_minus0(int space, char *charg);
void		ft_minus_cases(int	len, int space, unsigned int zero, char **charg);
void		ft_notminus_cases(int len, int space, unsigned int zero, char **charg, char *print);
int			ft_treat_decimal();
void		ft_check_flags(const char *format);
void		ft_printf2(char *print);
int			ft_dot_function(char *format);
void    	ft_printdec_case1(int space, unsigned int zero, char **charg);
void		ft_printdec_case2(int len, int space, char **charg);
void		ft_printdec_case3(int len, unsigned int zero, char **charg);
void		ft_printdec_case4(char **charg);
void		ft_printdec_case5(int space, unsigned int zero, char **charg);
void		ft_printdec_case6(int len, unsigned int space, char **charg);
void		ft_treat_char();
void		ft_treat_string(char *format);
void		ft_final(int space, int zero, char *charg);

#endif

