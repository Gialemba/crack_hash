/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:57:36 by tali              #+#    #+#             */
/*   Updated: 2024/01/22 21:57:37 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/ft_printf.h"
#define FLAG "sidcupxX%j"

static int	pf(char c, va_list va)
{
	if (c == 's')
		return (ft_putstr(va_arg(va, char *)));
	else if (c == 'i')
		return (ft_putinbr(va_arg(va, int), 0));
	else if (c == 'd')
		return (ft_putinbr(va_arg(va, int), 0));
	else if (c == 'c')
		return (ft_putchar(va_arg(va, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(va, unsigned long int), 0));
	else if (c == 'p')
		return (ft_printadr(va_arg(va, void *)));
	else if (c == 'x')
		return (ft_printhex(va_arg(va, unsigned int), 0));
	else if (c == 'X')
		return (ft_printhexmaj(va_arg(va, unsigned int), 0));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'j')
		return (ft_printilst(va_arg(va, t_list *), 0));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		i2;
	va_list	va;

	if (!s)
		return (0);
	i2 = 0;
	i = 0;
	va_start(va, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr(FLAG, s[i + 1]))
			i2 += pf(s[++i], va) - 2;
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(va);
	return (i + i2);
}
