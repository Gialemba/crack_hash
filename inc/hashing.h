/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:22:48 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 01:04:32 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHING_H
# define HASHING_H

/*	lib	*/
# include "../libft/include_h/libft.h"

/*	struct	*/
//MD5
typedef struct	md5_s{

	uint64_t	size;		// len of the input after padding
	uint32_t	buffer[4];	// current accumulation of hash
	uint32_t	input[16];	// input to be used in the next step
	uint8_t		digest[16];	// result of algorithm

}				md5_t;

// SHA1
typedef struct	sha1_s{

	uint64_t	len;		// len of the input after padding
	uint32_t	hash[5];	// current accumulation of hash
	uint32_t	input[16];	// input to be used in the next step
	uint8_t		digest[20];	// result of algorithm

}				sha1_t;

//SHA256
typedef struct	sha256_s{

	uint64_t	len;		// len of the input after padding
	uint32_t	input[16];	// input to be used in the next step
	uint32_t	hash[8];	// current accumulation of hash
	uint8_t		digest[32];	// result of algorithm

}				sha256_t;

//SHA224
typedef struct	sha224_s{

	uint64_t	len;		// len of the input after padding
	uint32_t	input[16];	// input to be used in the next step
	uint32_t	hash[8];	// current accumulation of hash
	uint8_t		digest[28];	// result of algorithm

}				sha224_t;

//SHA512
typedef struct	sha512_s{

	uint64_t	len;		// len of the input after padding
	uint64_t	input[16];	// input to be used in the next step
	uint64_t	hash[8];	// current accumulation of hash
	uint8_t		digest[64];	// result of algorithm

}				sha512_t;

/*	function	*/
// main
uint32_t	ft_leftrotate32(uint32_t x, uint32_t offset);
uint64_t	ft_leftrotate64(uint64_t x, uint64_t offset);
uint32_t	ft_rightrotate32(uint32_t x, uint32_t offset);
uint64_t	ft_rightrotate64(uint64_t x, uint64_t offset);
uint32_t	ft_swap32(uint32_t num);
uint64_t	ft_swap64(uint64_t num);

// MD5
void			ft_md5(md5_t *md5, uint8_t *s);
unsigned char	*ft_md5_padding(md5_t *md5, uint8_t *s, size_t l);
void			ft_md5_algo(md5_t *md5);

//SHA1
void			ft_sha1(sha1_t *sha1, uint8_t *s);
unsigned char	*ft_sha1_padding(sha1_t *sha1, uint8_t *s, size_t l);
void			ft_sha1_algo(sha1_t *sha1);

//SHA256
void			ft_sha256(sha256_t *sha256, uint8_t *s);
unsigned char	*ft_sha256_padding(sha256_t *sha256, uint8_t *s, size_t l);
void			ft_sha256_algo(sha256_t *sha256);

//SHA224
void			ft_sha224(sha224_t *sha224, uint8_t *s);
unsigned char	*ft_sha224_padding(sha224_t *sha224, uint8_t *s, size_t l);
void			ft_sha224_algo(sha224_t *sha224);

//SHA512
void			ft_sha512(sha512_t *sha512, uint8_t *s);
unsigned char	*ft_sha512_padding(sha512_t *sha512, uint8_t *s, size_t l);
void			ft_sha512_algo(sha512_t *sha512);

#endif
