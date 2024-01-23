/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:54:28 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:54:30 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	tmp;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	tmp = size * nmemb;
	if (tmp / size != nmemb)
		return (NULL);
	else
	{
		ret = malloc(nmemb * size);
		if (!(ret))
			return (NULL);
	}
	ft_bzero(ret, tmp);
	return (ret);
}
