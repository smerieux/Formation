/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:05:24 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:05:55 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_itob(unsigned int n)
{
	int				tab[15];
	int				x;
	int				i;
	unsigned int	bin;

	x = 0;
	bin = 0;
	i = 0;
	while (i < 8)
	{
		tab[x] = n % 2;
		n /= 2;
		x++;
		i++;
	}
	i = x;
	while (--i > 0)
		bin = bin + (tab[i] * ft_pow(10, i));
	return (bin);
}
