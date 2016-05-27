/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:07:53 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:08:07 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1) + 1;
	if (len > n)
	{
		if ((s2 = ft_strnew(n)) == NULL)
			return (NULL);
		else
			ft_strncpy(s2, s1, n);
	}
	else
	{
		if ((s2 = ft_strnew(len)) == NULL)
			return (NULL);
		else
			ft_strncpy(s2, s1, len);
	}
	return (s2);
}
