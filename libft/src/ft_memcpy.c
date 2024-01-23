/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:01 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:02 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;
	size_t		i;

	if (!src && !dest)
		return (NULL);
	src2 = (const char *)src;
	dest2 = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
