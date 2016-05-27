/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:36:22 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:17:27 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*ptr_s1;
	size_t		len;

	ptr_s1 = s1;
	len = ft_strlen(s2);
	if (len > n)
		return (NULL);
	while (*ptr_s1 && n--)
	{
		if (ft_memcmp(ptr_s1, s2, len) == 0)
			return ((char *)ptr_s1);
		ptr_s1 += 1;
	}
	return (NULL);
}
