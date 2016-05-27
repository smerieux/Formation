/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:08:47 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:09:03 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	**ft_tabdup(char **tab)
{
	int		len;
	int		i;
	char	**new;

	i = -1;
	len = ft_tablen(tab);
	if ((new = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	while (++i < len)
		new[i] = ft_strdup(tab[i]);
	new[i] = NULL;
	return (new);
}
