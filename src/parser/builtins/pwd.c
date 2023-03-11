/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:43:48 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/06 18:48:14 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd_cmd(void)
{
	char	*temp;

	temp = getcwd(0, 0);
	if (!temp)
		return ;
	else
		printf("%s\n", temp);
	free(temp);
	g_global.error = 0;
}
