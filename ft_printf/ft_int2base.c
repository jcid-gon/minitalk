/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:29:34 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/09/07 11:37:59 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int2base(unsigned long int dec, int base, int *ret)
{
	if (dec / base > 0)
	{
		ft_int2base(dec / base, base, ret);
		if (dec % base < 10)
			ftprint_putnbr_fd(dec % base, 1, ret);
		else
			ftprint_putchar_fd(dec % base + 87, 1, ret);
	}
	else
	{
		if (dec < 10)
			ftprint_putnbr_fd(dec, 1, ret);
		else
			ftprint_putchar_fd(dec + 87, 1, ret);
	}
}
