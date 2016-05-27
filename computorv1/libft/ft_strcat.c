/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:09:34 by smerieux          #+#    #+#             */
/*   Updated: 2013/11/29 13:57:27 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char		*ptr_s1;
	const char	*ptr_s2;

	ptr_s1 = s1 + ft_strlen(s1);
	ptr_s2 = s2;
	while (*ptr_s2 != '\0')
	{
		*ptr_s1++ = *ptr_s2++;
	}
	*ptr_s1 = '\0';
	return (s1);
}
