/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:32:01 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:18:41 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*cpy;

	cpy = dest;
	while (n > 0)
	{
		*cpy++ = *src++;
		n -= 1;
	}
	while (n > 0)
	{
		*cpy++ = 0;
		n -= 1;
	}
	return (dest);
}
