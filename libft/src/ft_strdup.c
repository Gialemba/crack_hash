/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:58:53 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 22:24:09 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	new_s = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
