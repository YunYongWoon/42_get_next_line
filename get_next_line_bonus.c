/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:51 by yoyun             #+#    #+#             */
/*   Updated: 2022/03/26 22:32:33 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(char *save[], int fd)
{
	char	*buf;
	int		size;

	size = 1;
	while (!find_nl(save[fd]) && size)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (free_save(save, -1));
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (free_save(save, fd));
		}
		save[fd] = gnl_strjoin(save, buf, size, fd);
		free(buf);
	}
	return (save[fd]);
}

char	*make_output(char *save[], int fd)
{
	size_t	size;
	size_t	i;
	char	*output;

	if (!save[fd])
		return (NULL);
	size = 0;
	while (save[fd][size] && save[fd][size] != '\n')
		size++;
	if (save[fd][size] == '\n')
		size++;
	output = (char *)malloc(sizeof(char) * (size + 1));
	if (!output)
		return (free_save(save, -1));
	i = -1;
	while (++i < size)
		output[i] = save[fd][i];
	output[i] = 0;
	return (output);
}

char	*renew_save(char *save[], int fd)
{
	size_t	start;
	size_t	len;

	if (!save[fd])
		return (NULL);
	start = 0;
	len = gnl_strlen(save[fd]);
	while (save[fd][start] != '\n' && save[fd][start])
		start++;
	if (save[fd][start] == '\n')
		start++;
	return (gnl_substr(save, start, len - start, fd));
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*output;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	save[fd] = read_file(save, fd);
	if (!save[fd])
		return (NULL);
	output = make_output(save, fd);
	save[fd] = renew_save(save, fd);
	return (output);
}
