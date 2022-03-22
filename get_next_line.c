/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:51 by yoyun             #+#    #+#             */
/*   Updated: 2022/03/22 17:59:28 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *save)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	while (!ft_gnl_strchr(save, '\n') && bytes)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		save = ft_gnl_strjoin(save, buf);
		free(buf);
	}
	free(buf);
	return (save);
}

char	*make_output(char *save)
{
	size_t	i;
	char	*output;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!i)
		return (NULL);
	output = (char *)malloc(sizeof(char) * (i + 2));
	if (!output)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		output[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		output[i++] = '\n';
	output[i] = '\0';
	return (output);
}

char	*renew_save(char *save)
{
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_gnl_strlen(save);
	while (save[start] == '\n' || !save[start])
		start++;
	return (ft_gnl_substr(save, start, len - start));
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	output = make_output(save);
	if (!output)
		return (NULL);
	save = renew_save(save);
	return (output);
}