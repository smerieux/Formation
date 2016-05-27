/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:57:11 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/08 16:53:08 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr_s;
	size_t	i;

	ptr_s = (unsigned char *) s;
	i = 0;
	while (n--)
	{
		ptr_s[i] = '\0';
		i += 1;
	}
}
