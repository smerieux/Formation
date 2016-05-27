/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:04:29 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:10:29 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void		ft_free_tab(char ***tab)
{
	int		i;

	i = ft_tablen(*tab);
	if (*tab)
	{
		while (i >= 0)
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
			i--;
		}
		free(*tab);
		*tab = NULL;
	}
}
