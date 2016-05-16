/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:01:32 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:08:53 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ptr_s1;
	const char	*ptr_s2;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	if (ptr_s2 <= ptr_s1)
	{
		ptr_s1 += n - 1;
		ptr_s2 += n - 1;
		while (n > 0)
		{
			*ptr_s1-- = *ptr_s2--;
			n -= 1;
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
