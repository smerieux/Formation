/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:37:17 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:00:44 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != (char)c)
	{
		if (*ptr == 0)
			return (NULL);
		ptr += 1;
	}
	return ((char *)ptr);
}
