/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:59:51 by tali              #+#    #+#             */
/*   Updated: 2024/01/25 18:34:31 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hashing.h"

uint32_t	ft_leftrotate32(uint32_t x, uint32_t offset)
{
	return ( x << offset ) | ( x >> (32 - offset));
}

uint64_t	ft_leftrotate64(uint64_t x, uint64_t offset)
{
	return ( x << offset ) | ( x >> (64 - offset));
}

uint32_t	ft_rightrotate32(uint32_t x, uint32_t offset)
{
	return (x >> offset % 32) | (x << (32 - offset) % 32);
}

uint64_t	ft_rightrotate64(uint64_t x, uint64_t offset)
{
	return (x >> offset % 64) | (x << (64 - offset) % 64);
}

uint32_t	ft_swap32(uint32_t num)
{
	uint32_t	swapped;

	swapped =	((num>>24)&0xff) | // move byte 3 to byte 0
				((num<<8)&0xff0000) | // move byte 1 to byte 2
				((num>>8)&0xff00) | // move byte 2 to byte 1
				((num<<24)&0xff000000); // byte 0 to byte 3
	return (swapped);
}

uint64_t	ft_swap64(uint64_t value)
{
	return	((value & 0x00000000000000FF) << 56) |
			((value & 0x000000000000FF00) << 40) |
			((value & 0x0000000000FF0000) << 24) |
			((value & 0x00000000FF000000) << 8)  |
			((value & 0x000000FF00000000) >> 8)  |
			((value & 0x0000FF0000000000) >> 24) |
			((value & 0x00FF000000000000) >> 40) |
			((value & 0xFF00000000000000) >> 56);
}
 
int	ft_char_to_hex(uint8_t nb, uint8_t **s, int i)
{
	char		*base;


	base = "0123456789abcdef";
	if (nb >= 16)
		ft_char_to_hex(nb / 16, s, i++);
	uint8_t temp[2] = {base[nb % 16], 0};
	ft_strlcat((char *)*s, (char *)temp, ft_strlen((char *)*s) + 2);
	return (i);
}

uint8_t	*ft_str_to_hex(uint8_t *s, uint64_t len)
{
	uint8_t		*ret = ft_calloc(len + 1, sizeof(uint8_t));
	uint32_t	i = 0;

	while (i < len / 2)
	{
		uint8_t	tmp[2] = {'0', 0};

		if (ft_char_to_hex(s[i], &ret, 0) == 0)
		{
			uint8_t		t;
			uint64_t	len = ft_strlen((char *)ret);

			ft_strlcat((char *)ret, (char *)tmp, len + 2);
			t = ret[len];
			ret[len] = ret[len - 1];
			ret[len - 1] = t;
		}
		i++;
	}

	return (ret);
}
