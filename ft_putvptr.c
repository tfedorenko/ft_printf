/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfedoren <tfedoren@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:04:41 by tfedoren          #+#    #+#             */
/*   Updated: 2022/02/18 16:04:41 by tfedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putvptr (void *ptr)
{
    int i;

    i = 0;
    if(!ptr)
      i += ft_putstr("0x0");
    else
    {
	  	i += ft_putstr("0x");
		  i += ft_puthnbr(((unsigned long long int)ptr), 0);
    }
	return (i);
}