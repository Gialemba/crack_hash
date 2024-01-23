/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:00:01 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 22:00:02 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i2;

	if (!big && !len)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	i2 = 0;
	while (big[i] && i < len)
	{
		i2 = 0;
		while (i + i2 < len && little[i2] && big[i + i2] == little[i2])
			i2++;
		if (!(little[i2]))
			return ((char *)big + i);
		else
			i2 = 0;
		i++;
	}
	return (NULL);
}
