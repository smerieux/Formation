/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:30:18 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:14:51 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*p_dst;
	const char	*p_src;
	size_t		n;
	size_t		len;

	p_dst = dst;
	p_src = src;
	n = size;
	while (n-- && *p_dst)
		p_dst += 1;
	len = p_dst - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(p_src));
	while (*p_src)
	{
		if (n != 1)
		{
			*p_dst++ = *p_src;
			n -= 1;
		}
		p_src += 1;
	}
	*p_dst = '\0';
	return (len + (p_src - src));
}
