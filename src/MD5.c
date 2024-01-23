/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MD5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:53:55 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 01:07:25 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hashing.h"

// shift amounts per round
const uint32_t S[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,//    0..15
						5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,//    16..31
						4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,//    32..47
						6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};//   48..63

// K[i] = floor(2^32 × abs(sin(i + 1))) precomputed table
const uint32_t K[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,//  0..3
						0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,//  4..7
						0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,//  8..11
						0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,//  12..15
						0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,//  16..19
						0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,//  20..23
						0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,//  24..27
						0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,//  28..31
						0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,//  32..35
						0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,//  36..39
						0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,//  40..43
						0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,//  44..47
						0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,//  48..51
						0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,//  52..55
						0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,//  56..59
						0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};// 60..63

// main function calling other one
void	ft_md5(md5_t *md5, uint8_t *s)
{
	uint8_t	*new_s;

	new_s = ft_md5_padding(md5, s, ft_strlen((char *)s));
	md5->buffer[0] = 0x67452301;
	md5->buffer[1] = 0xefcdab89;
	md5->buffer[2] = 0x98badcfe;
	md5->buffer[3] = 0x10325476;

	// run algo on each block of 512 bit
	uint32_t	block = 0;

	while (md5->size > block) 
	{
		ft_memcpy(md5->input, new_s + block , 64);// 512 bit / 8 (1 byte = 8 bit) = 64 byte
		ft_md5_algo(md5);
		block += 64;
	}
	free(new_s);
	ft_memcpy(md5->digest, md5->buffer, 16); // 128 / 8
}

// binary operation according to md5 algo (thx wikipedia) 
#define E(B, C, D) ((B & C) | ((~B) & D))
#define G(B, C, D) ((D & B) | ((~D) & C))
#define H(B, C, D) (B ^ C ^ D)
#define I(B, C, D) (C ^ (B | (~D)))

// md5 algorythm according to wikipedia
void	ft_md5_algo(md5_t *md5)
{
	uint32_t	i;
	uint32_t	A = md5->buffer[0];
	uint32_t	B = md5->buffer[1];
	uint32_t	C = md5->buffer[2];
	uint32_t	D = md5->buffer[3];

	i = 0;
	while (i < 64)
	{
		uint32_t	f;
		uint32_t	g;

		if (i < 16)
		{
			f = E(B, C, D);
			g = i;
		}
		else if (i < 32)
		{
			f = G(B, C, D);
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			f = H(B, C, D);
			g = (3 * i + 5) % 16;
		}
		else if (i < 64)
		{
			f = I(B, C, D);
			g = (7 * i) % 16;
		}
		f += A + K[i] + md5->input[g];
		A = D;
		D = C;
		C = B;
		B += ft_leftrotate32(f, S[i]);
		i++;
	}
	md5->buffer[0] += A;
	md5->buffer[1] += B;
	md5->buffer[2] += C;
	md5->buffer[3] += D;
}

// padding of the main string
unsigned char	*ft_md5_padding(md5_t *md5, uint8_t *s, size_t l)
{
	size_t	new_len = l + 8;
	uint8_t	*new_s;

	while(++new_len % 64 != 0);// 512 / 8
	md5->size = new_len;
	new_s = (uint8_t *)malloc(new_len + 1);
	ft_memcpy(new_s, s, l);
	new_s[l] = 0x80;

	size_t	i = l + 1;

	while (i < new_len - 8)
	{
		new_s[i] = 0x00;
		i++;
	}

	// append the len to the padding
	new_s[i + 3] = l >> 21;
	new_s[i + 2] = l >> 13;
	new_s[i + 1] = l >> 5;
	new_s[i + 0] = l << 3;
	new_s[i + 7] = l >> 53;
	new_s[i + 6] = l >> 45;
	new_s[i + 5] = l >> 37;
	new_s[i + 4] = l >> 29;

	return (new_s);
}
