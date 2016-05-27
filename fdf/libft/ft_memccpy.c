/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:25:09 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:01:27 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (ptr_s2[i] == (unsigned char)c)
		{
			ptr_s1[i] = ptr_s2[i];
			return (s1 + 1 + i);
		}
		else
			ptr_s1[i] = ptr_s2[i];
		i += 1;
	}
	return (NULL);
}
