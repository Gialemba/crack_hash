/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:00:37 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 22:00:38 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_s;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_s = ft_calloc(len + 1, sizeof(char));
	if (!(new_s))
		return (NULL);
	while (s[start + i] && i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
