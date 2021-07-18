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

void    ft_treat_all()
{
    char *charg;

    charg = ft_itoa(flags.arg);
    ft_putstr(charg);
    free(charg);
}

char    *ft_dectohex(int arg)
{
    int i;
    char *str;
    int mod;

    i = 0;
    while (arg)
    {
        mod = arg % 16;
        arg /= 16;
        if (mod > 9)
        {
            if (flags.areg == 1)
                 mod += 55;
            else
                mod += 87;
        }
        else
            mod+=48;
        str[i] = mod;
        // printf("\nstri------%c\n",str[i]);
        // printf("\nmod-----%d\n", mod);
        // printf("\ncheck\n");
        i++;
    }
    printf("\nstr---%s\n", str);
    str[i] = '\0';
    return(str);
}

void    ft_treat_hexa()
{
    int arg;
    flags.arg = va_arg(flags.list, unsigned int);
    arg = flags.arg;

    ft_dectohex(arg);
}