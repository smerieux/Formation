/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:37:17 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/16 14:06:22 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnchr(const char *s, int c, size_t n)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != (char) c && n)
	{
		ptr += 1;
		n--;
	}
	if (n == 0)
		return (NULL);
	return ((char *) ptr);
}
