/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:59:52 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:22:39 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (!*s2)
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1)
	{
		if (ft_memcmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1 += 1;
	}
	return (NULL);
}
