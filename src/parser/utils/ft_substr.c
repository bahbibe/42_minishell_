/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:46:17 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/02/25 11:39:05 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static	char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (n == -1)
		n = ft_strlen(src);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*final_str;
	size_t	real_len;

	if (!s)
		return (0);
	if (len > (int)ft_strlen(s))
		real_len = ft_strlen(s);
	else
		real_len = len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	final_str = malloc(sizeof(char ) * real_len + 1);
	if (!final_str)
		return (0);
	ft_strncpy(final_str, (char *) s + start, len);
	return (final_str);
}
