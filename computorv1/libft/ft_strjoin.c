/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:54:41 by smerieux          #+#    #+#             */
/*   Updated: 2015/05/28 15:05:35 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*res;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	x = 0;
	if ((res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	while (s1[i] != '\0')
		res[x++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[x++] = s2[i++];
	res[x] = '\0';
	return (res);
}
