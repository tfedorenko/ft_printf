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

static int	ft_conversions(char ch, va_list *ap, int count)
{
	if (ch == '%')
		count += ft_putchar('%');
	else if (ch == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (ch == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (ch == 'p')
		count += ft_putvptr(va_arg(*ap, void *));
	else if (ch == 'd' || ch == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (ch == 'u')
		count += ft_putudnbr(va_arg(*ap, unsigned int));
	else if (ch == 'x')
		count += ft_puthnbr(va_arg(*ap, unsigned int), 0);
	else if (ch == 'X')
		count += ft_puthnbr(va_arg(*ap, unsigned int), 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

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
