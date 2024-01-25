/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:24:47 by tali              #+#    #+#             */
/*   Updated: 2024/01/25 22:21:25 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/crack.h"

char	*ft_rmnewline(char *s)
{
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (s[len - 1] == '\n')
	{
		size_t	i = 0;
		ret = (char *)malloc(len - 1);
		while (i < len - 2)
		{
			ret[i] = s[i];
			i++;
		}
		ret[i] = 0;
		free(s);
		return (ret);
	}
	else
		return (s);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int		fd = open("dico/rockyou2000.txt", O_RDONLY);

		if (fd <= 0)
		{
			printf("error open\n");
			exit(0);
		}
		printf("Currently working on it\n");
		int64_t	i = 1;
		int64_t	j = 0;
		int64_t	len = ft_strlen(av[1]);
		while (1)
		{
			uint8_t	*temp;
			char *s = get_next_line(fd);
			s = ft_rmnewline(s);
			if (!s && j == 1)
			{
				printf("not found in this dico\nNumber of attempt : %ld\n", i);
				free(s);
				if (temp)
					free(temp);
				close(fd);
				exit(0);
			}
			else
			{
				if (!s)
					j++;
				if (len == 32)
				{
					md5_t	md5;
					ft_md5(&md5, (uint8_t *)s);
					temp = ft_str_to_hex(md5.digest, len);
				}
				else if (len == 40)
				{
					sha1_t	sha1;
					ft_sha1(&sha1, (uint8_t *)s);
					temp = ft_str_to_hex(sha1.digest, len);
				}
				else if (len == 64)
				{
					sha256_t	sha256;
					ft_sha256(&sha256, (uint8_t *)s);
					temp = ft_str_to_hex(sha256.digest, len);
				}
				else if (len == 56)
				{
					sha224_t	sha224;
					ft_sha224(&sha224, (uint8_t *)s);
					temp = ft_str_to_hex(sha224.digest, len);
				}
				else if (len == 128)
				{
					sha512_t	sha512;
					ft_sha512(&sha512, (uint8_t *)s);
					temp = ft_str_to_hex(sha512.digest, len);
				}
				else
				{
					printf("format not reconized are you sure it's in MD5 - SHA1 - SHA224 - SHA256 - SHA512 ?\n");
					free(s);
					close(fd);
					exit(0);
				}
				if (ft_strncmp((char *)temp, av[1], len) == 0)
				{
					printf("\nFOUND !\n%s\nThis is the value before hash\nNumber of attempt : %ld\n", s, i);
					free(s);
					free(temp);
					close(fd);
					exit(0);
				}
				free(temp);
				temp = NULL;
			}
			free(s);
			i++;
		}
	}
	else
		printf("using :\t%s [hashed string]\n", av[0]);
	return (0);
}
