/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:38:28 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/08 17:09:26 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*ptr_s1;
	const char	*ptr_s2;

	ptr_s1 = s1 + ft_strlen(s1);
	ptr_s2 = s2;
	while (*ptr_s2 != '\0' && n > 0)
	{
		*ptr_s1++ = *ptr_s2++;
		n -= 1;
	}
	*ptr_s1 = '\0';
	return (s1);
}
