/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:59:42 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:59:43 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ns;

	i = 0;
	ns = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!(ns))
		return (NULL);
	while (s[i])
	{
		ns[i] = (*f)(i, s[i]);
		i++;
	}
	return (ns);
}
