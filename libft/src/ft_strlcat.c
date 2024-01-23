/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:59:15 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:59:17 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	if ((!src || !dst) && size == 0)
		return (0);
	i = ft_strlen(dst);
	if (i > size)
		return (size + ft_strlen(src));
	i2 = ft_strlen(src);
	if (i2 == 0)
		return (i);
	if (size == 0)
		return (i2);
	i2 = 0;
	while (i + i2 < size - 1 && src[i2])
	{
		dst[i + i2] = src[i2];
		i2++;
	}
	dst[i + i2] = 0;
	return (i + ft_strlen(src));
}
