/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:55:34 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:55:36 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

int	ft_getlen(int n)
{
	int		i;
	size_t	nu;

	i = 1;
	if (n < 0)
	{
		i++;
		nu = (size_t)n * -1;
	}
	else
		nu = (size_t)n;
	while (nu > 9)
	{
		nu /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	size_t	new_n;
	int		a;

	if (n < 0)
		a = -1;
	else
		a = 1;
	i = ft_getlen(n);
	new_n = (size_t)n * a;
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (new_n > 9)
	{
		i--;
		s[i] = (new_n % 10) + '0';
		new_n /= 10;
	}
	s[i - 1] = new_n + '0';
	if (a == -1)
		s[i - 2] = '-';
	return (s);
}
