#include "ft_printf.h"

void    ft_final(int space, int zero, char *charg)
{
    if (flags.negative == 0)
    {
        while (space > 0)
        {
            ft_putchar(' ');
            space--;
        }
    }
    while (zero > 0)
    {
        ft_putchar('0');
        zero--;
    }
    if (flags.pz)
        ft_putstr(charg);
    if (flags.negative == 1)
    {
        while(space > 0)
        {
            ft_putchar(' ');
            space--;
        }
    }
    return ;
}

void    ft_treat_decimal()
{
    int space;
    int zero;
    int len;
    char    *charg;

    space = 0;
    zero = 0;
    charg = ft_itoa(flags.arg);
    len = ft_strlen(charg);
    if (flags.arg < 0)
        flags.negative = 1;
    if (!flags.width && !flags.prec && !flags.minus && !flags.zero && flags.dot)
    {
        free(charg);
        return ;
    }
    // ete leny amenamecna >> miayn tiv
    // ete miayn tara tvac >> miayn tiv
    // ete width == 0&& prec == 0 >> miayn tiv
    if (flags.arg < 0)
        flags.minus = 1;
    else if (flags.width && !flags.dot)
        space = flags.width - len;
    else if (flags.width == 0 && flags.prec > len && flags.arg == 0 && flags.dot)
    {
        zero = flags.prec;
        flags.pz = 0;
    }
    else if (flags.width && flags.prec)
    {
        if (flags.width > flags.prec && flags.prec > len )
        {
            zero = flags.prec - len;
            space = flags.width - zero;
        }
        else if (flags.width > len && flags.prec < len)
            space = flags.width - len;
        else if (len > flags.width && len < flags.prec && flags.arg)
            zero = flags.prec - len;
        else if (len > flags.prec && flags.width > len)
            space = flags.width - len;
        else if (flags.width == 0 && flags.prec > len && flags.arg)
            zero = flags.prec - len;
        else if (flags.prec == 0 && flags.width > len)
            space = flags.width - len;
        else if (flags.width == flags.prec)
            zero = flags.prec;
    }
    ft_final(space, zero, charg);
    free(charg);
}

// void    ft_treat_pointer()
// {
//     flags.arg = va_arg(flags.list, unsigned long);
//     // int *add;
//     char *str;
//     char *s1;
//     size_t ret;
//     size_t  sadd;
//     int count;

//     s1 = "0x7ff";
//     flags.sarg = &flags.arg;
//     sadd = (size_t)flags.sarg;
//     printf("\nsarg---%d\n", flags.sarg);
//     printf("\narg---%zu\n", sadd);
//     ret = flags.sarg;
//     while (ret)
//     {
//         ret /= 16;
//         count++;
//     }
//     // printf("\nadd---%zu\n", add);
//     str = malloc(count + 16);
//     if (!str)
//         return ;
//     // str = ft_dectohex(sadd);
//     // printf("\nstr---%s\n", str);
//     // str = ft_strjoin(s1, str);
//     ft_putstr(s1);
//     ft_putstr(str);
//     free(str);
// }

void    ft_treat_pointer()
{
    int *address;
    int ret;
    char *str;
    size_t arg;

    flags.sarg = va_arg(flags.list, size_t);
    ft_putstr("0x");
    if (flags.sarg == 0)
    {
        // ft_putstr("0x");
        ft_putchar('0');
        return ;
    }
    // flags.sarg = (size_t)flags.unarg;
    // arg = flags.sarg;
    str = ft_dectohex(flags.sarg);
    ft_putstr(str);
    free(str);
}

char    *ft_dectohex(size_t arg)
{
    int i;
    char *str;
    int mod;
    int count;

    count = 0;
    i = 0;
    while (arg)
    {
        arg /= 16;
        count++;
    }
    str = malloc(count + 1);
    if (!str)
    {
        return (0);
    }
    // printf("\nsarg---%zu\n", flags.sarg);
    i = count - 1;

    while (flags.sarg)
    {
        mod = flags.sarg % 16;
        flags.sarg /= 16;
        if (mod > 9)
        {
            if (flags.areg == 1)
                 mod += 55;
            else
                mod += 87;
        }
        else
            mod += 48;
        str[i] = mod;
        i--;
    }
    return(str);
}

void    ft_treat_hexa()
{
    char *str;
    size_t arg;
    flags.sarg = va_arg(flags.list, unsigned int);
    arg = flags.sarg;

    if (arg == 0)
    {
        ft_putchar('0');
        return ;
    }
    str = ft_dectohex(arg);
    ft_putstr(str);
    free(str);
}