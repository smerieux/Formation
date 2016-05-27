/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:23:13 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 16:59:26 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr_b;
	size_t			i;

	ptr_b = (unsigned char *)b;
	i = 0;
	while (len--)
	{
		ptr_b[i] = (unsigned char)c;
		i += 1;
	}
	return (b);
}
