/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:54 by yoyun             #+#    #+#             */
/*   Updated: 2022/04/01 14:36:19 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_save(char *save)
{
	if (save)
		free(save);
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

char	*gnl_strjoin(char *save, char *buf, size_t size)
{
	size_t	save_size;
	size_t	i;
	char	*join_output;

	save_size = gnl_strlen(save);
	if ((save_size + size) == 0)
		return (free_save(save));
	join_output = (char *)malloc(sizeof(char) * (save_size + size + 1));
	if (!join_output)
		return (free_save(save));
	i = 0;
	while (i < save_size)
	{
		join_output[i] = save[i];
		i++;
	}
	while (i < size + save_size)
	{
		join_output[i] = buf[i - save_size];
		i++;
	}
	join_output[save_size + size] = 0;
	free_save(save);
	return (join_output);
}

char	*gnl_substr(char *save, size_t start, size_t len)
{
	char	*substr_output;
	size_t	i;

	if (len == 0)
		return (free_save(save));
	substr_output = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr_output)
		return (free_save(save));
	i = 0;
	while (i < len)
	{
		substr_output[i] = save[start + i];
		i++;
	}
	substr_output[i] = 0;
	free(save);
	return (substr_output);
}
