/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:56:34 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:56:36 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cell;

	cell = (t_list *)malloc(sizeof(t_list));
	if (!cell)
		return (NULL);
	cell->content = content;
	cell->index = 0;
	cell->next = NULL;
	return (cell);
}
