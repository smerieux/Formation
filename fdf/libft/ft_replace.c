/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 15:07:26 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/08 17:09:26 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_replace(char **s, char old, char new)
{
	char	*tmp;
	char	*stock;
	int		len;

	len = ft_strlen(*s);
	stock = *s;
	while ((tmp = ft_strchr(stock, old)))
	{
		*tmp = new;
		stock = tmp + 1;
	}
	return (len);
}
