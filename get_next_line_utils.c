/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:54 by yoyun             #+#    #+#             */
/*   Updated: 2022/03/20 15:15:11 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	char	*output;

	s1_size = ft_gnl_strlen(s1);
	s2_size = ft_gnl_strlen(s2);
	output = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!output)
		return (NULL);
	i = -1;
	while (++i < s1_size)
		output[i] = s1[i];
	i = -1;
	while (++i < s2_size)
		output[i + s1_size] = s2[i];
	output[i] = 0;
	if (!s1)
		free(s1);
	return (output);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int	i;

	if(!s)
		return (NULL);
	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		if (!s[i])
			break ;
		i++;
	}
	return (NULL);
}