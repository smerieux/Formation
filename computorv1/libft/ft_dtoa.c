/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 14:43:58 by smerieux          #+#    #+#             */
/*   Updated: 2015/06/01 17:59:48 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_dtoa(double n)
{
	int			tmp;
	char		*res;

	res = NULL;
	if (n < 0)
	{
		n *= -1;
		res = ft_strdup("-");
	}
	tmp = (int)n;
	res = ft_strjoin(res, ft_itoa(tmp));
	res = ft_strjoin(res, ".");
	n -= (double)tmp;
	n *= 1000000;
	res = ft_strjoin(res, ft_itoa((int)n));
	return (res);
}
