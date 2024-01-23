/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:08 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:09 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest2 < src2)
	{
		while (n > i)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dest2[n] = src2[n];
	}
	dest = (void *)dest2;
	return ((void *)dest);
}
