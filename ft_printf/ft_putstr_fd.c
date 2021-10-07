/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:10:05 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/09/07 11:35:47 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftprint_putstr_fd(char *s, int fd, int *ret)
{
	int	index;

	if (!s)
		s = "(null)";
	index = 0;
	while (s[index] != '\0')
	{
		ftprint_putchar_fd(s[index], fd, ret);
		index++;
	}
}
