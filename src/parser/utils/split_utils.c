/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:21:54 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/02/25 11:19:56 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	includes(char c, char *sep)
{
	int	i;

	i = -1;
	while (sep[++i])
		if (sep[i] == c)
			return (1);
	return (0);
}
