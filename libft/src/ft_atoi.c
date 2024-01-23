/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:53:52 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:54:10 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	sum;
	int		i;
	int		a;

	a = 0;
	i = 0;
	sum = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)) && nptr[i])
		i++;
	if (nptr[i] == '-')
	{
		a++;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		sum = (sum * 10) + (nptr[i] - '0');
		i++;
	}
	if (a)
		return ((int)sum * -1);
	return ((int)sum);
}
