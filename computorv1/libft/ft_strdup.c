/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:55:20 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:10:30 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = NULL;
	if (s)
	{
		cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (cpy)
			ft_strcpy(cpy, s);
	}
	return (cpy);
}
