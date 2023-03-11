/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:57:06 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/03 21:02:53 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	skip_sign(char *nb, int *i, int *sign)
{
	int	j;

	j = 0;
	*sign = 1;
	while (nb[*i] == '-' || nb[*i] == '+')
	{
		if (nb[*i] == '-')
			*sign = -1;
		j++;
		++*i;
	}
	if (j > 1)
		return (0);
	return (1);
}

long long	ft_atoi(char *nb)
{
	size_t		i;
	int			sign;
	long long	n;

	i = 0;
	n = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	if (!skip_sign(nb, (int *)&i, &sign))
		return (0);
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		n *= 10;
		n += (nb[i] - '0');
		i++;
	}
	return (n * sign);
}
