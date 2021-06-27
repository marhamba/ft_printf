#include "./srcs/ft_printf.h"

int	main()
{
	// int a = 10;
	
	ft_printf("my --- %05d\n", -43);
	printf("or --- %05d\n", -43);
	ft_printf("my --- %.6d\n", -3);
	printf("or --- %.6d\n", -3);
	ft_printf("my --- %8.5d\n", 34);
	printf("or --- %8.5d\n", 34);
	ft_printf("my --- %7d\n", -33);
	printf("or --- %7d\n", -33);
	ft_printf("my --- %05d\n", 43);
	printf("or --- %05d\n", 43);	
	ft_printf("my --- %07d\n", -54);	
	printf("or --- %07d\n", -54);	
	ft_printf("my ---%08.5d\n", 34);
	printf("or ---%08.5d\n", 34);
	ft_printf("my --- %010.5d\n", -216);
	printf("or --- %010.5d\n", -216);
}
//"%05d", 43
//"%07d", -54
//"%8.5d", 34
//"%7d", 33
//"%08.5d", 34
//"%010.5d", -216
//"%05d", 43
//"%07d", -54
//%08.5d", 34