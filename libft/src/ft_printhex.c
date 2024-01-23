/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:44 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:45 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/ft_printf.h"

int	ft_printhexmaj(unsigned int nb, int i2)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
		i2 += ft_printhexmaj(nb / 16, i2);
	ft_putchar(base[nb % 16]);
	return (i2 + 1);
}

int	ft_printhex(unsigned int nb, int i2)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
		i2 += ft_printhex(nb / 16, i2);
	ft_putchar(base[nb % 16]);
	return (i2 + 1);
}
