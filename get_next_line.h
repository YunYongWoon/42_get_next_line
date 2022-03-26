/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyun <yoyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:40:44 by yoyun             #+#    #+#             */
/*   Updated: 2022/03/26 18:26:56 by yoyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// # define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*free_save(char *save);
int		find_nl(char *save);
size_t	gnl_strlen(char *s);
char	*gnl_strjoin(char *save, char *buf, size_t size);
char	*gnl_substr(char *save, size_t start, size_t len);

#endif