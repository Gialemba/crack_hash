/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:59:08 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:59:10 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	s = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		s[i + i2] = s2[i2];
		i2++;
	}
	return (s);
}
