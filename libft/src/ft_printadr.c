/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:30 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:31 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/ft_printf.h"

int	ft_printadr(void *ptr)
{
	int			i2;
	uintptr_t	nptr;

	i2 = 1;
	if (!ptr)
		return (ft_putstr("(nil)"));
	nptr = (uintptr_t)ptr;
	ft_printadr2(nptr);
	while (nptr >= 16)
	{
		nptr /= 16;
		i2++;
	}
	return (i2 + 2);
}

void	ft_printadr2(uintptr_t ptr)
{
	unsigned int	x;
	char			*base;

	base = "0123456789abcdef";
	x = ptr % 16;
	if (ptr >= 16)
	{
		ft_printadr2(ptr / 16);
		write(1, &base[x], 1);
	}
	else
	{
		write(1, "0x", 2);
		write(1, &base[x], 1);
	}
}
