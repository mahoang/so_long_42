/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:00:22 by mahoang           #+#    #+#             */
/*   Updated: 2021/07/24 16:31:48 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 8

int			get_next_line(int fd, char **line);
//int			ft_readline(char **stock, int fd);
char	*ft_readline(char *stock, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strcpy(char *dest, const char *src);
size_t		ft_strlen(const char *str);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *src);
void		*ft_calloc(size_t count, size_t size);
#endif
