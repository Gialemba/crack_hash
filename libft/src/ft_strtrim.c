/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:00:29 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 22:00:30 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*new_s;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]))
		len--;
	new_s = ft_substr(s1, i, len + 1 - i);
	if (!new_s)
		return (NULL);
	return (new_s);
}
