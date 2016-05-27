/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:55:20 by smerieux          #+#    #+#             */
/*   Updated: 2015/05/27 12:00:00 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s, int len)
{
	char	*cpy;

	cpy = NULL;
	if (s)
	{
		cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (cpy)
			ft_strncpy(cpy, s, len);
	}
	return (cpy);
}
