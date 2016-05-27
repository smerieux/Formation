/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:32:33 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/08 17:01:29 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;

	ptr_s = (const unsigned char *) s;
	while (n--)
	{
		if (*ptr_s == (unsigned char) c)
			return ((void *) ptr_s);
		ptr_s += 1;
	}
	return (NULL);
}
