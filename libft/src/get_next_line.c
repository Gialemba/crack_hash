/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tali <tali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:01:04 by tali              #+#    #+#             */
/*   Updated: 2024/01/23 23:17:09 by tali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_h/get_next_line.h"

/*
char	*ft_strdup2(const char *s)
{
	char	*new_s;
	size_t	i;

	i = 0;
	new_s = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
*/

char	*gnl_read(int fd, char *str)
{
	char	*buff;
	char	*tmp;
	ssize_t	max;

	max = 1;
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	while (max > 0 && !gnl_have_nl(str))
	{
		max = read(fd, buff, BUFFER_SIZE);
		if (max < 0)
		{
			free(buff);
			return (NULL);
		}
		if (max == 0)
			break ;
		if (!str)
			str = ft_strdup("");
		tmp = ft_strjoin(str, buff);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	free(buff);
	return (str);
}

char	*gnl_output(char *str)
{
	size_t	i;
	char	*output;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	output = (char *)ft_calloc(i + 1, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		output[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		output[i] = '\n';
	return (output);
}

char	*gnl_rm_output(char *str)
{
	size_t	i;
	size_t	i2;
	char	*tmp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n' && str[i + 1])
	{
		tmp = (char *)ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		i2 = 0;
		while (str[++i])
			tmp[i2++] = str[i];
		free(str);
		return (tmp);
	}
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[64];
	char		*tmp;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd >= 64)
		return (NULL);
	str[fd] = gnl_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	tmp = gnl_output(str[fd]);
	str[fd] = gnl_rm_output(str[fd]);
	return (tmp);
}
