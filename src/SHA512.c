/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SHA512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:28:16 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 01:02:08 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/hashing.h"

/*
typedef struct	sha512_s{

	uint64_t	len;
	uint64_t	input[16];
	uint64_t	hash[8];
	uint8_t		digest[64];

}				sha512_t;
*/

static uint64_t	K[80] ={0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538, 
						0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe, 
						0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 
						0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 
						0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab, 
						0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725, 
						0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 
						0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b, 
						0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218, 
						0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 
						0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 
						0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec, 
						0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c, 
						0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6, 
						0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 
						0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

void	ft_sha512(sha512_t *sha512, uint8_t *s)
{
	uint8_t	*new_s = ft_sha512_padding(sha512, s, ft_strlen((char *)s));

	sha512->hash[0] = 0x6a09e667f3bcc908;
	sha512->hash[1] = 0xbb67ae8584caa73b;
	sha512->hash[2] = 0x3c6ef372fe94f82b;
	sha512->hash[3] = 0xa54ff53a5f1d36f1;
	sha512->hash[4] = 0x510e527fade682d1;
	sha512->hash[5] = 0x9b05688c2b3e6c1f;
	sha512->hash[6] = 0x1f83d9abfb41bd6b;
	sha512->hash[7] = 0x5be0cd19137e2179;

	uint64_t	block = 0;
	while (sha512->len > block)
	{
		ft_memcpy(sha512->input, new_s + block, 128);
		for (int i = 0; i < 16; i++)
			sha512->input[i] = ft_swap64(sha512->input[i]);
		ft_sha512_algo(sha512);
		block += 128;
	}
	for (int i = 0; i < 8; i++)
		sha512->hash[i] = ft_swap64(sha512->hash[i]);
	ft_memcpy(sha512->digest, sha512->hash, 64);
	free(new_s);
}

void	ft_sha512_algo(sha512_t *sha512)
{
	uint64_t	w[80];
	uint64_t	s0;
	uint64_t	s1;

	ft_memset(w, 0, 128);
	ft_memcpy(w, sha512->input, 128);
	for (int i = 16; i < 80; i++)
	{
		s0		= ft_rightrotate64(w[i-15], 1) ^ ft_rightrotate64(w[i-15], 8) ^ w[i-15] >> 7;
		s1		= ft_rightrotate64(w[i-2], 19) ^ ft_rightrotate64(w[i-2], 61) ^ w[i-2] >> 6;
		w[i]	= w[i-16] + s0 + w[i-7] + s1;
	}

	uint64_t	A = sha512->hash[0];
	uint64_t	B = sha512->hash[1];
	uint64_t	C = sha512->hash[2];
	uint64_t	D = sha512->hash[3];
	uint64_t	E = sha512->hash[4];
	uint64_t	F = sha512->hash[5];
	uint64_t	G = sha512->hash[6];
	uint64_t	H = sha512->hash[7];
	uint64_t	i = 0;

	while (i < 80)
	{
		uint64_t	ch, maj, temp1, temp2;

		s1		= ft_rightrotate64(E, 14) ^ ft_rightrotate64(E, 18) ^ ft_rightrotate64(E, 41);
		ch		= (E & F) ^ ((~E) & G);
		temp1	= H + s1 + ch + K[i] + w[i];
		maj		= (A & B) ^ (A & C) ^ (B & C);
		s0		= ft_rightrotate64(A, 28) ^ ft_rightrotate64(A, 34) ^ ft_rightrotate64(A, 39);
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
	sha512->hash[0] += A;
	sha512->hash[1] += B;
	sha512->hash[2] += C;
	sha512->hash[3] += D;
	sha512->hash[4] += E;
	sha512->hash[5] += F;
	sha512->hash[6] += G;
	sha512->hash[7] += H;
}

unsigned char	*ft_sha512_padding(sha512_t *sha512, uint8_t *s, size_t l)
{
	size_t	new_len = l + 16;
	uint8_t	*new_s;

	while(++new_len % 128 != 0);// 1024 / 8
	sha512->len = new_len;
	new_s = (uint8_t *)malloc(new_len);
	ft_memcpy(new_s, s, l);
	new_s[l] = 0x80;

	size_t	i = l + 1;

	while (i < new_len - 8)
	{
		new_s[i] = 0x00;
		i++;
	}

	// append the len in bit to the padding
	unsigned __int128 l2 = l << 3;

	new_s[i + 7] = l2;
	new_s[i + 6] = l2 >> 8;
	new_s[i + 5] = l2 >> 16;
	new_s[i + 4] = l2 >> 24;
	new_s[i + 3] = l2 >> 32;
	new_s[i + 2] = l2 >> 40;
	new_s[i + 1] = l2 >> 48;
	new_s[i + 0] = l2 >> 56;

	return (new_s);
}
