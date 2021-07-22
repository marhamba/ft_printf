#include "./srcs/ft_printf.h"
#include <limits.h>

char *ft_dectohex(size_t arg)
{
    int count;
    int mod;
    char *str;

    count = 0;
    while (arg)
    {
        arg /= 16;
        count++;
    }
    str = malloc(count + 1);
	if (!str)
		return (0);
    // count -= 1;
    while(count)
    {
        mod = flags.sarg % 16;
		flags.sarg /= 16;
        // if (mod > 9)
        // {
        //     // if (flags.areg == 1)
        //     //     mod += 55;
        //     // else
        //     //     mod += 86;
        // }
        // else
        //     mod += 48;
        str[count] = ft_itoa(mod);
        count--;
    }
    printf("check---%s\n", str);
    free(str);
}

int	main()
{	
	ft_dectohex(45);
	// printf("real - %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
}
