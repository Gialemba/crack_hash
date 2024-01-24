/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SHA1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:52:14 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 01:07:17 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hashing.h"

/*
typedef struct	sha1_s{

	uint64_t	len;
	uint32_t	hash[5];
	uint32_t	input[16];
	uint8_t		digest[20];

}				sha1_t;
*/

void	ft_sha1(sha1_t *sha1, uint8_t *s)
{
	uint8_t	*new_s = ft_sha1_padding(sha1, s, ft_strlen((char *)s));

	sha1->hash[0] = 0x67452301;
	sha1->hash[1] = 0xEFCDAB89;
	sha1->hash[2] = 0x98BADCFE;
	sha1->hash[3] = 0x10325476;
	sha1->hash[4] = 0xC3D2E1F0;

	uint64_t	block = 0;
	while (sha1->len > block)
	{
		ft_memcpy(sha1->input, new_s + block, 64);
		for (int i = 0; i < 16; i++)
			sha1->input[i] = ft_swap32(sha1->input[i]);
		ft_sha1_algo(sha1);
		block += 64;
	}
	for (int i = 0; i < 5; i++)
		sha1->hash[i] = ft_swap32(sha1->hash[i]);
	ft_memcpy(sha1->digest, sha1->hash, 20);
	free(new_s);
}

void	ft_sha1_algo(sha1_t *sha1)
{
	uint32_t	A = sha1->hash[0];
	uint32_t	B = sha1->hash[1];
	uint32_t	C = sha1->hash[2];
	uint32_t	D = sha1->hash[3];
	uint32_t	E = sha1->hash[4];
	uint32_t	w[80];

	ft_memset(w, 0, 80);
	ft_memcpy(w, sha1->input, 64);
	for (int i = 16; i < 80; i++)
		w[i] = ft_leftrotate32(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);

	uint64_t	i = 0;
	while(i < 80)
	{
		uint32_t	f;
		uint32_t	k;
		if (i < 20)
		{
			f = (B & C) | ((~B) & D);
			k = 0x5A827999;
		}
		else if (i < 40)
		{
			f = B ^ C ^ D;
			k = 0x6ED9EBA1;
		}
		else if (i < 60)
		{
			f = (B & C) | (B & D) | (C & D);
			k = 0x8F1BBCDC;
		}
		else if (i < 80)
		{
			f = B ^ C ^ D;
			k = 0xCA62C1D6;
		}
		uint32_t	temp = ft_leftrotate32(A, 5) + f + E + k + w[i];
		E = D;
		D = C;
		C = ft_leftrotate32(B, 30);
		B = A;
		A = temp;
		i++;
	}
	sha1->hash[0] += A;
	sha1->hash[1] += B;
	sha1->hash[2] += C;
	sha1->hash[3] += D;
	sha1->hash[4] += E;
}

unsigned char	*ft_sha1_padding(sha1_t *sha1, uint8_t *s, size_t l)
{
	size_t	new_len = l + 8;
	uint8_t	*new_s;

	while(++new_len % 64 != 0);// 512 / 8
	sha1->len = new_len;
	new_s = (uint8_t *)malloc(new_len + 1);
	ft_memcpy(new_s, s, l);
	new_s[l] = 0x80;

	size_t	i = l + 1;

	while (i < new_len - 8)
	{
		new_s[i] = 0x00;
		i++;
	}

	// append the len in bit to the padding
	new_s[i + 7] = l << 3;
	new_s[i + 6] = l >> 5;
	new_s[i + 5] = l >> 13;
	new_s[i + 4] = l >> 21;
	new_s[i + 3] = l >> 29;
	new_s[i + 2] = l >> 37;
	new_s[i + 1] = l >> 45;
	new_s[i + 0] = l >> 53;

	return (new_s);
}
