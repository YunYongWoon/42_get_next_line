/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:40:44 by yoyun             #+#    #+#             */
/*   Updated: 2022/03/23 11:29:02 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

size_t	ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_substr(char *s, size_t start, size_t len);
char	*get_next_line(int fd);

#endif