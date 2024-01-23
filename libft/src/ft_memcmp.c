/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:56:54 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:56:56 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	if (!s1 && !s2)
		return (0);
	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ns1[i] != (unsigned char)ns2[i])
			return ((int)(ns1[i] - ns2[i]));
		i++;
	}
	return (0);
}
