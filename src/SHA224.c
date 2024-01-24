/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SHA224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:14:57 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 01:06:49 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hashing.h"

/*
typedef struct	sha224_s{

	uint64_t	len;
	uint32_t	input[16];
	uint32_t	hash[8];
	uint8_t		digest[28];

}				sha224_t;
*/

static uint32_t	K[64] ={0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
						0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
						0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
						0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
						0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
						0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
						0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
						0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void	ft_sha224(sha224_t *sha224, uint8_t *s)
{
	uint8_t	*new_s = ft_sha224_padding(sha224, s, ft_strlen((char *)s));

	sha224->hash[0] = 0xc1059ed8;
	sha224->hash[1] = 0x367cd507;
	sha224->hash[2] = 0x3070dd17;
	sha224->hash[3] = 0xf70e5939;
	sha224->hash[4] = 0xffc00b31;
	sha224->hash[5] = 0x68581511;
	sha224->hash[6] = 0x64f98fa7;
	sha224->hash[7] = 0xbefa4fa4;

	uint64_t	block = 0;
	while (sha224->len > block)
	{
		ft_memcpy(sha224->input, new_s + block, 64);
		for (int i = 0; i < 16; i++)
			sha224->input[i] = ft_swap32(sha224->input[i]);
		ft_sha224_algo(sha224);
		block += 64;
	}
	for (int i = 0; i < 8; i++)
		sha224->hash[i] = ft_swap32(sha224->hash[i]);
	ft_memcpy(sha224->digest, sha224->hash, 28);
	free(new_s);
}

void	ft_sha224_algo(sha224_t *sha224)
{
	uint32_t	w[64];
	uint32_t	s0;
	uint32_t	s1;

	ft_memset(w, 0, 64);
	ft_memcpy(w, sha224->input, 64);
	for (int i = 16; i < 64; i++)
	{
		s0 = ft_rightrotate32(w[i-15], 7) ^ ft_rightrotate32(w[i-15], 18) ^ w[i-15] >> 3;
		s1 = ft_rightrotate32(w[i-2], 17) ^ ft_rightrotate32(w[i-2], 19) ^ w[i-2] >> 10;
		w[i] = w[i-16] + s0 + w[i-7] + s1;
	}

	uint32_t	A = sha224->hash[0];
	uint32_t	B = sha224->hash[1];
	uint32_t	C = sha224->hash[2];
	uint32_t	D = sha224->hash[3];
	uint32_t	E = sha224->hash[4];
	uint32_t	F = sha224->hash[5];
	uint32_t	G = sha224->hash[6];
	uint32_t	H = sha224->hash[7];
	uint32_t	i = 0;

	while (i < 64)
	{
		uint32_t	ch, maj, temp1, temp2;

		s1		= ft_rightrotate32(E, 6) ^ ft_rightrotate32(E, 11) ^ ft_rightrotate32(E, 25);
		ch		= (E & F) ^ ((~E) & G);
		temp1	= H + s1 + ch + K[i] + w[i];
		s0		= ft_rightrotate32(A, 2) ^ ft_rightrotate32(A, 13) ^ ft_rightrotate32(A, 22);
		maj		= (A & B) ^ (A & C) ^ (B & C);
		temp2	= s0 + maj;

		H = G;
		G = F;
		F = E;
		E = D + temp1;
		D = C;
		C = B;
		B = A;
		A = temp1 + temp2;

		i++;
	}
	sha224->hash[0] += A;
	sha224->hash[1] += B;
	sha224->hash[2] += C;
	sha224->hash[3] += D;
	sha224->hash[4] += E;
	sha224->hash[5] += F;
	sha224->hash[6] += G;
	sha224->hash[7] += H;
}

unsigned char	*ft_sha224_padding(sha224_t *sha224, uint8_t *s, size_t l)
{
	size_t	new_len = l + 8;
	uint8_t	*new_s;

	while(++new_len % 64 != 0);// 512 / 8
	sha224->len = new_len;
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
