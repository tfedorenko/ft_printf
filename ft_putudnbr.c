/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putudnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:21:28 by tfedoren          #+#    #+#             */
/*   Updated: 2022/02/18 20:21:28 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unbrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putudnbr(unsigned int n)
{
	int	i;

	i = ft_unbrlen(n);
	if (n >= 10)
	{
		ft_putudnbr(n / 10);
		ft_putudnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (i);
}
