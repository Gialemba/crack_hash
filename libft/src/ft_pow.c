/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:24 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:25 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

int	ft_pow(int nb, int power)
{
	int	nb_b;

	nb_b = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		nb = nb * nb_b;
		power--;
	}
	return (nb);
}
