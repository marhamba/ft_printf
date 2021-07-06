// #include "ft_printf.h"

// int	ft_treat_decimal()
// {
// 	char	*charg;
// 	int		len;
// 	int		space;
// 	int		zero;

// 	if (flags.width < 0)
// 	{
// 		flags.width *= -1;
// 		flags.minus = 1;
// 		flags.zero = 0;
// 	}
// 	if (flags.arg < 0)
// 	{
// 		flags.negative = 1;
// 		flags.arg = flags.arg * (-1);
// 	}
// 	charg = ft_itoa(flags.arg);
// 	len = ft_strlen(charg);
// 	if (flags.negative)
// 		len++;
// 	if (flags.negative && flags.zero)
// 		zero = flags.width - len;
// 	else if (flags.negative && flags.dot)
// 		zero = flags.prec - (len - 1);
// 	else
// 		zero = flags.zero ? flags.width - len : flags.prec - len;
// 	space = flags.width - len;
// 	if (flags.dot && flags.prec > len)
// 		space -= zero;
//     // printf("\nzero - %d, minus - %d, width - %d, prc - %d, arg - %d\n\n", flags.zero, flags.minus, flags.width, flags.prec, flags.arg);
// 	if (flags.minus && flags.width > len)
// 	{
// 		if (flags.negative == 1 && flags.arg != INT_MIN)
// 			ft_putchar('-');
// 		if ((flags.isprec == 0 && flags.width && flags.arg == 0 && flags.dot && flags.prec == 0)
// 			|| (flags.width && flags.arg == 0 && flags.dot && flags.prec == 0))
// 		{
// 				flags.pz = 0; 
// 				space += 1;
// 				while (space > 0)
// 				{
// 					ft_putchar(' ');
// 					space--;
// 				}
// 		}
// 		if (flags.dot && zero > 0 && !(flags.width && flags.prec && flags.arg == 1))
// 		{
// 			while (zero)
// 			{
// 				ft_putchar('0');
// 				zero--;
// 			}
// 		}
// 		if (flags.width && flags.prec && flags.arg == INT_MIN)
// 		{
// 			space += 1;
// 			flags.arg *= (-1);
// 			flags.minus = 0;
// 		}
// 		if (flags.minus)
// 		{
//                         // printf("check\n\n\n");
// 			while (zero > 0)
// 			{
// 				ft_putchar('0');
// 				zero--;
// 			}
// 			if (flags.pz)
// 				ft_putstr(charg);
// 			else if (flags.width > flags.prec && flags.arg > 0)
// 				space = flags.width - len;
// 			else if (flags.width > flags.prec && flags.prec > len && flags.arg != 0 && flags.width - flags.prec == len)
// 				space -= 1;
// 			else if (flags.prec == len && flags.width > flags.prec && flags.arg == 1)
// 				space -= 1;
// 			else if ((flags.width - flags.prec) < len && flags.negative)
// 				space = 0;
// 			else if (flags.width > flags.prec && flags.prec > len && flags.width - flags.prec > len)
// 				space = flags.width - flags.prec;
// 			else if (flags.width > flags.prec && flags.prec > len && flags.negative && flags.minus)
// 				space -= 1; 

// 			while (space > 0)
// 			{
// 				ft_putchar(' ');
// 				space--;
// 			}
// 		}
// 		if (!flags.minus)
// 		{
// 			while (space > 0)
// 			{
// 				ft_putchar(' ');
// 				space--;
// 			}
// 		}
// 		if (flags.width && flags.prec && flags.arg == 1 && !flags.minus)
// 		{
// 			while (zero > 0)
// 			{
// 				ft_putchar('0');
// 				zero--;
// 			}
// 		}
// 		if (!flags.minus)
// 		{
// 			if (flags.pz)
// 				ft_putstr(charg);
// 		}
// 	}
// 	else
// 	{
// 		if (flags.width == 0 && flags.prec == 0 && flags.arg == 0 && flags.star && flags.dot)
// 			flags.pz = 1;
// 		else if (flags.width == 0 && flags.dot && flags.isprec == 0 && flags.arg == 0 && flags.prec == 0)
//         {
//             free(charg);
// 			return (0);
//         }
// 		else if (flags.arg == 0 && flags.isprec == 0 && (flags.width == 0 || flags.width > 0 || (flags.zero && flags.width > 0)))
// 				flags.arg = 0;
// 		else if ((flags.prec == 0 && flags.arg == 0 && flags.isprec == 0) ||  (flags.prec == 0 && flags.arg == 0 && flags.width == 0))
//         {
//             free(charg);
// 			return (0);
//         }
// 		else if (flags.width && flags.prec == 0 && flags.isprec == 1 && flags.arg == 0 && !flags.zero)
// 		{
// 			space = flags.width < 0 ? flags.width * -1 : flags.width;
// 			flags.pz = 0;
// 			while (space > 0)
// 			{
// 				ft_putchar(' ');
// 				space--;
// 			}
// 		}
// 		if (!flags.zero)
// 		{
// 			if (flags.width && flags.isprec == 0 && flags.arg == 0 && flags.pz == 0)
// 				space += 1;
// 			if (flags.prec == len && flags.width > flags.prec && flags.arg == 1)
// 				space -= 1;
// 			while (space > 0)
// 			{
// 				ft_putchar(' ');
// 				space--;
// 			}
// 		}
// 		else if (flags.zero && !flags.minus && flags.prec && !flags.negative && flags.width)
// 		{
// 			space = flags.width - flags.prec;
// 			zero = flags.prec - len;
// 			if (flags.prec < len)
// 				space -= 1;
// 			while (space > 0)
// 			{
// 				ft_putchar(' ');
// 				space--;
// 			}
// 			while (zero > 0)
// 			{
// 				ft_putchar('0');
// 				zero--;
// 			}
//             // printf("check\n\n\n");
// 		}
// 		else if (flags.zero && flags.minus)
// 		{
// 			if (flags.negative)
// 				space--;
// 			zero = flags.width - len;
// 			if (flags.negative)
// 				zero = flags.width - space - 4;
// 			while (zero > 0)
// 			{
// 				ft_putchar('0');
// 				zero--;
// 			}
// 		}
// 		if (flags.negative && !(flags.dot && flags.zero && flags.negative && flags.width && !flags.minus))
// 			ft_putchar('-');
// 		if (flags.dot || flags.zero)
// 		{
// 			if (flags.dot && flags.zero)
// 			{
// 				if (flags.width > flags.prec && flags.zero && flags.prec == 0 && flags.isprec && flags.arg == 0)
// 				{
// 					flags.pz = 0;

// 				}
// 				space = flags.width - len;
// 				if (flags.negative)
// 					len -= 1;
// 				if (flags.prec == 0 && flags.isprec && flags.zero && flags.arg == 0)
// 					space = flags.width;
// 				else
// 				{
// 					space = zero;
// 					if (flags.width > flags.prec && flags.prec > len && flags.arg == 1)
// 					{
// 						zero = flags.prec - len;
// 						space = flags.width - zero;
// 					}
//                     if (flags.negative && flags.arg == INT_MIN)
//                     {
//                         flags.negative = 0;
//                         space += 1;
//                     }
//                     // printf("barev");
// 				}
				
// 				if (!(flags.width && flags.prec > 0 && len == 1 && flags.arg == 1 && flags.prec != 1))
// 				{
// 					flags.zero = 0;
// 					zero = 0;
//                     if (flags.width < flags.prec && flags.star && flags.negative)
//                     {
//                         zero = flags.prec - len;
//                         space = 0;
//                     }
// 				}
// 				else
// 				{
// 					zero = flags.width - len - 1;
// 					if (flags.width < flags.prec)
// 						zero = flags.width;
// 					if (flags.width == flags.prec)
// 						zero += 1;
// 					space = 0;
// 					if (flags.width > flags.prec && flags.prec > len && flags.arg == 1)
// 					{ // stex1
// 						zero = flags.prec - len;
// 						space = flags.width - (zero + len) - 1;
// 					}
// 				}
// 				if ((flags.width < flags.prec && flags.prec > len && flags.negative && flags.width < len && !flags.zero && flags.arg != 0 && zero == 0)
// 					|| (flags.width > flags.prec && flags.prec > len && flags.negative && !flags.zero && zero == 0))
// 					{
// 						zero = flags.prec - len;
// 						if (flags.width > flags.prec && flags.prec > len && flags.negative && !flags.zero)
// 							space = flags.width - zero - len - 1;
// 					}
// 				while (space > 0)
// 				{
// 					ft_putchar(' ');
// 					space--;
// 				}
// 				if (flags.negative)
// 				{
// 					ft_putchar('-');
// 					flags.negative = 0;
// 				}
// 				while (zero > 0 )
// 				{
// 					ft_putchar('0');
// 					zero--;
// 				}
// 			}
// 			if (flags.isprec == 0 && flags.width && flags.arg == 0 && flags.dot && flags.prec == 0)
// 			{
// 				flags.pz = 0;
// 				space += 1;
// 				while (space > 0)
// 				{
// 					ft_putchar(' ');
// 					space--;
// 				}
// 			}
// 			if (flags.dot && flags.zero && flags.negative && flags.width && !flags.minus)
// 			{
// 				space = flags.width - flags.prec - 1;
// 				zero = flags.prec - len + 1;
// 				if (flags.prec && flags.prec < len && flags.negative)
// 					space -= 1;
// 				while (space > 0)
// 				{
// 					ft_putchar(' ');
// 					space--;
// 				}
// 				if (flags.negative)
// 				{
// 					ft_putchar('-');
// 					flags.negative = 0;
// 				}
// 			}
// 			if (!(flags.width && flags.prec > 0 && len == 1 && flags.arg == 1))
// 			{
// 				while (zero > 0)
// 				{
// 					ft_putchar('0');
// 					zero--;
// 				}
// 			}
// 		}
// 		if (flags.pz)
// 			ft_putstr(charg);
// 	}
// 	free(charg);
// 	return(0);
// }