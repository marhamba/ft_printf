#include "./srcs/ft_printf.h"
#include <limits.h>

int	main()
{
	// int a = 10;
	// ft_printf("my1--- %d |\n", 0);
	// printf("or1--- %d |\n", 0);
	// printf("\n");
	// ft_printf("my2--- %.d |\n", 0);
	// printf("or2--- %.d |\n", 0);
	// printf("\n");
	// ft_printf("my3--- %-.2d |\n", 0);
	// printf("or3--- %-.2d |\n", 0);
	// printf("\n");
	// ft_printf("my4--- %-2.2d |\n", 0);
	// printf("or4--- %-2.2d |\n", 0);
	// printf("\n");
	// ft_printf("my5--- %-3.2d |\n", 0);
	// printf("or5--- %-3.2d |\n", 0);
	// printf("\n");
	// ft_printf("my6--- %-3.2d %10.42d |\n", 0, 0);
	// printf("or6--- %-3.2d %10.42d |\n", 0, 0);
	// printf("\n");
	// ft_printf("my7--- %-3.2d %10.42d |\n", 1, -1);
	// printf("or7--- %-3.2d %10.42d |\n", 1, -1);
	// printf("\n");
	// ft_printf("my8--- %-3.2d %10.42d |\n", 10, -10);
	// printf("or8--- %-3.2d %10.42d |\n", 10, -10);
	// printf("\n");
	// ft_printf("my9--- *%-*.*d* *%*.*d* |\n", 4, 5, 10, 10, 21, -10);
	// printf("or9--- *%-*.*d* *%*.*d* |\n", 4, 5, 10, 10, 21, -10);
	// printf("\n");
	// ft_printf("my10--- *%-*.*d* *%*.*d* |\n", 6, 2, 102, 10, 21, -101);
	// printf("or10--- *%-*.*d* *%*.*d* |\n", 6, 2, 102, 10, 21, -101);
	// printf("\n");
	// ft_printf("my11--- *%*.*d* *%*.*d* |\n", -6, 2, 102, 10, 21, 101);
	// printf("or11--- *%*.*d* *%*.*d* |\n", -6, 2, 102, 10, 21, 101);
	// printf("\n");
	// ft_printf("my12--- 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	// printf("or12--- 0*%0-*.*d*0 0*%0*.*d*0 \n", 6, 2, 102, 10, 21, -101);
	// ft_printf("my13--- 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	// printf("or13--- 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	// ft_printf("my14--- 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	// printf("or14--- 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	// ft_printf("my15--- 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	// printf("or15--- 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	// ft_printf("my16--- --0*   %0*.0d*0 ___ 0*%0*.10d*0-- |\n", -2, 0, 21, 1);
	// printf("or16--- --0*   %0*.0d*0 ___ 0*%0*.10d*0-- |\n", -2, 0, 21, 1);
	// printf("\n");
	// ft_printf("my55 ---%011.2d\n", UINT_MAX);
	// printf("or55 ---%011.2d\n", UINT_MAX);
	// ft_printf("my56 ---%09.2d\n", UINT_MAX);
	// ft_printf("%010.5d\n", -216);
	// printf("or69---%.0d\n", 0);
	// ft_printf("%-10c%*c%c*\n",'0', 10, '1', '2');
	// printf("%-10c%*c%c*",'0', 10, '1', '2');
	// printf("or2--- %.d ", 0);
	// ft_printf("my --- --0*%0*.0d*0 second 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	// printf("or --- --0*%0*.0d*0 second 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	// ft_printf("%09.0d\n", UINT_MAX);
	// // int a = UINT_MAX - 2147483648;
	// printf("%09.0ld", ULONG_MAX);
	// printf("%-5.d", 0);
// 	ft_printf("my --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
// 	printf("or --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
// "%010.0d", UINT_MAX + 1
	// printf("%.d", 0);
	// ft_printf("%0*.10d\n", 21, 1);
	// printf("%0*.10d", 21, 1);
	// ft_printf(" --0*%-0*.20d*0 0*\n", -21, CHAR_MAX);
	// printf(" --0*%-0*.20d*0 0*", -21, CHAR_MAX);
	printf("%0.0d", 0);
}
