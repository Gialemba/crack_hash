/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:56:48 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:56:49 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s2;

	s2 = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
