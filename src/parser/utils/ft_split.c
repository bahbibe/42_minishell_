/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:43 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/03 19:07:49 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static	int	calc_element(const char *s, char *sep, size_t *x, size_t *j)
{
	size_t	i;
	size_t	len;

	*x = 0;
	*j = 0;
	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!includes(s[i], sep))
			if (includes(s[i + 1], sep) || s[i + 1] == '\0')
				len++;
		i++;
	}
	return (len);
}

static	void	get_next_str(const char *str, char *sep, size_t *i, size_t *j)
{
	*j = *i;
	while (str[*i])
	{
		if (includes(str[*i], sep))
		{
			++*i;
			++*j;
		}
		else
			break ;
	}
}

static int	substr_and_alloc_check(char **final_str, const char *s,
				int j, int len)
{
	*final_str = ft_substr(s, j, len);
	if (!final_str)
		return (0);
	return (1);
}

char	**free_tab(char **tab, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(tab[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char *sep)
{
	char	**final_str;
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	if (!s)
		return (0);
	if (!calc_element(s, sep, &x, &j) || !ft_strlen(s))
		return (NULL);
	final_str = ft_calloc(sizeof(char *), calc_element(s, sep, &x, &j) + 1);
	get_next_str(s, sep, &i, &j);
	if (i-- == ft_strlen(s))
		return ((char *[1]){NULL});
	while (++i <= ft_strlen(s))
	{
		if (includes(s[i], sep) || s[i] == '\0')
		{
			if (!substr_and_alloc_check(&final_str[x++], s, j, i - j))
				return (free_tab(final_str, --x));
			get_next_str(s, sep, &i, &j);
		}
	}
	return (final_str);
}
