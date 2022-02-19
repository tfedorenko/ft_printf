/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:46:33 by tfedoren          #+#    #+#             */
/*   Updated: 2022/02/18 21:46:33 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hnbrlen(unsigned long long int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static void	ft_hnbr_format(unsigned int n, int format)
{
	if (format == 0)
	{
		ft_putchar('a' + n - 10);
	}
	if (format == 1)
	{
		ft_putchar('A' + n - 10);
	}
}

int	ft_puthnbr(unsigned long long int n, int format)
{
	unsigned int	i;

	i = ft_hnbrlen(n);
	if (n == 0)
		ft_putchar('0');
	else if (n >= 16)
	{
		ft_puthnbr(n / 16, format);
		ft_puthnbr(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_hnbr_format(n, format);
		}
	}
	return (i);
}
