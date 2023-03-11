/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:24:48 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 18:25:06 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*get_after_new(char *last);
char	*get_before_new(char *last);
char	*get_substring(char *str, size_t len);
size_t	get_str_len(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*check_read_return(char **last, char *line);
char	*free_func(char **s1);
char	*ft_strcpy(char *dest, char *src);

#endif