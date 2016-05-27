/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:51:51 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 17:28:03 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	if (s != NULL)
	{
		while (*s && len--)
		{
			ret[i] = s[start];
			i += 1;
			start += 1;
		}
		ret[i] = '\0';
	}
	return (ret);
}
