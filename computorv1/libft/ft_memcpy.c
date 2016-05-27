/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:39:19 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:08:22 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*ptr_s1;
	const char	*ptr_s2;
	size_t		i;

	ptr_s1 = (char *)s1;
	ptr_s2 = (const char *)s2;
	i = 0;
	while (n--)
	{
		ptr_s1[i] = ptr_s2[i];
		i += 1;
	}
	return ((void *)s1);
}
