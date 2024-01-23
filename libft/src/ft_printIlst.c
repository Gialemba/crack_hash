/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printIlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:50 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:51 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/ft_printf.h"

int	ft_printilst(t_list *a, int i2)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		i2 += ft_putinbr(*(int *)tmp->content, 0);
		i2 += ft_putchar(' ');
		tmp = tmp->next;
	}
	return (i2);
}
