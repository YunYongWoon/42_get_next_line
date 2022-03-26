/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:54 by yoyun             #+#    #+#             */
/*   Updated: 2022/03/26 22:17:20 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_save(char *save[], int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0)
	{
		while (i < OPEN_MAX)
		{
			if (save[i])
				free(save[i]);
			i++;
		}
	}
	else
		if (save[fd])
			free(save[fd]);
	return (NULL);
}

int	find_nl(char *save)
{
	size_t	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	gnl_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (size);
	while (s[size])
		size++;
	return (size);
}

char	*gnl_strjoin(char *save[], char *buf, size_t size, int fd)
{
	size_t	save_size;
	size_t	i;
	char	*join_output;

	save_size = gnl_strlen(save[fd]);
	if ((save_size + size) == 0)
		return (free_save(save, fd));
	join_output = (char *)malloc(sizeof(char) * (save_size + size + 1));
	if (!join_output)
		return (free_save(save, -1));
	i = 0;
	while (i < save_size)
	{
		join_output[i] = save[fd][i];
		i++;
	}
	while (i < size + save_size)
	{
		join_output[i] = buf[i - save_size];
		i++;
	}
	join_output[save_size + size] = 0;
	free_save(save, fd);
	return (join_output);
}

char	*gnl_substr(char *save[], size_t start, size_t len, int fd)
{
	char	*substr_output;
	size_t	i;

	if (len == 0)
		return (free_save(save, fd));
	substr_output = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr_output)
		return (free_save(save, -1));
	i = 0;
	while (i < len)
	{
		substr_output[i] = save[fd][start + i];
		i++;
	}
	substr_output[i] = 0;
	free(save[fd]);
	return (substr_output);
}
