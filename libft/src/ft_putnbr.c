/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:58:11 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:58:12 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/ft_printf.h"

int	getlen(unsigned int n)
{
	int				i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int nb)
{
	char			*s;
	int				i;

	i = getlen(nb);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (nb > 9)
	{
		i--;
		s[i] = (nb % 10) + '0';
		nb /= 10;
	}
	s[i - 1] = nb + '0';
	return (s);
}

int	ft_putunbr(unsigned int nb, int i2)
{
	char	*ret;

	ret = ft_unsigned_itoa(nb);
	i2 += ft_putstr(ret);
	free(ret);
	return (i2);
}

int	ft_putinbr(int nb, int i2)
{
	char	*ret;

	ret = ft_itoa(nb);
	i2 = ft_putstr(ret);
	free(ret);
	return (i2);
}
