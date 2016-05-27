/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:11:05 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/08 17:00:41 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memalloc(size_t size)
{
	void	*s;

	s = (void *)malloc(size * sizeof(void));
	if (!s)
		return (NULL);
	else
		ft_bzero(s, size);
	return (s);
}
