/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:51 by yoyun             #+#    #+#             */
/*   Updated: 2022/04/01 14:35:08 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *save, int fd)
{
	char	*buf;
	int		size;

	size = 1;
	while (!find_nl(save) && size)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (free_save(save));
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (free_save(save));
		}
		save = gnl_strjoin(save, buf, size);
		free(buf);
	}
	return (save);
}

char	*make_output(char *save)
{
	size_t	size;
	size_t	i;
	char	*output;

	if (!save)
		return (NULL);
	size = 0;
	while (save[size] && save[size] != '\n')
		size++;
	if (save[size] == '\n')
		size++;
	output = (char *)malloc(sizeof(char) * (size + 1));
	if (!output)
		return (free_save(save));
	i = -1;
	while (++i < size)
		output[i] = save[i];
	output[i] = 0;
	return (output);
}

char	*renew_save(char *save)
{
	size_t	start;
	size_t	len;

	if (!save)
		return (NULL);
	start = 0;
	len = gnl_strlen(save);
	while (save[start] != '\n' && save[start])
		start++;
	if (save[start] == '\n')
		start++;
	return (gnl_substr(save, start, len - start));
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(save, fd);
	if (!save)
		return (NULL);
	output = make_output(save);
	save = renew_save(save);
	return (output);
}
