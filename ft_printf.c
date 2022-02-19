/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:15:17 by tfedoren          #+#    #+#             */
/*   Updated: 2022/01/21 23:15:17 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int ft_conversions(char ch, va_list *ap, int count)
{
	if (ch == '%')
		count += ft_putchar('%');
	else if (ch == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (ch == 's')
		count += ft_putstr(va_arg(*ap, char*));
	else if (ch == 'p')	
		count += ft_putvptr(va_arg(*ap, void*));
	else if (ch == 'd' || ch == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (ch == 'u')
		count += ft_putudnbr(va_arg(*ap, unsigned int));
	else if (ch == 'x')
		count += ft_puthnbr(va_arg(*ap, unsigned int), 0);
	else if (ch == 'X')
		count += ft_puthnbr(va_arg(*ap, unsigned int), 1);
	/*printf("\n");
	printf("%i", count);
	printf("\n");*/
	return (count);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	size_t i;
	int count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count = ft_conversions(str[i + 1], &ap, count);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}

/*int main()
{
	unsigned int a;
	unsigned int *b;

	a = 0;
	b = &a;
	/*ft_printf("H %% \n");
	printf("H %% \n");
	ft_printf("Hi %c \n", 'w');
	printf("Hi %c \n", 'w');
	ft_printf("Hello %s ! \n", "world");
	printf("Hello %s ! \n", "world");*/
	/*ft_printf("%x\n", 0);
	printf("%x\n", 0);
	ft_printf("Hello %d \n", -1234567);
	printf("Hello %d \n", -1234567);
	ft_printf("Hello %u \n", 12345672);
	printf("Hello %u \n", 12345672);
	ft_printf("Hello %x \n", 29);
	printf("Hello %x \n", 29);
	ft_printf("Hello %X \n", 29);
	printf("Hello %X \n", 29);*/
	/*ft_printf("Hello %p %p \n", 0, 0);
	printf("Hello %p %p \n", 0, 0);
	return(0);
}*/