/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:25:31 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/11 15:21:09 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_after_new(char *last)
{
	size_t	i;
	char	*str;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
		{
			str = get_substring(last + (i + 1), get_str_len(last + (i + 1)));
			free(last);
			return (str);
		}
		i++;
	}
	return (last);
}

char	*get_before_new(char *last)
{
	size_t	i;

	i = 0;
	while (last[i])
	{
		if (last[i] == '\n')
			return (get_substring(last, i + 1));
		i++;
	}
	return (last);
}

char	*get_substring(char *str, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final_str;
	int		total_len;
	int		i;

	i = 0;
	total_len = get_str_len(s1) + get_str_len(s2);
	final_str = malloc(sizeof(char) * (total_len + 2));
	if (!final_str)
		return (0);
	if (!s1)
		s1 = get_substring("", 0);
	ft_strcpy(final_str, s1);
	i = get_str_len(final_str);
	if (s2)
		ft_strcpy(final_str + i, s2);
	free(s1);
	return (final_str);
}
