/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 12:36:04 by smerieux          #+#    #+#             */
/*   Updated: 2015/05/28 18:57:31 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_atof(const char *s)
{
	int			i;
	int			x;
	double		sign;
	double		res;

	i = 0;
	x = 0;
	res = 0;
	while (s[i] == ' ')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	i += (s[i] == '-' || s[i] == '+') ? 1 : 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i] && s[i] != '.' && s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	i += (s[i] == '.') ? 1 : 0;
	while (s[i + x] && (s[i + x] >= '0' && s[i + x] <= '9'))
		res = res * 10 + (s[i + x++] - '0');
	while (x-- > 0)
		res /= 10;
	return (res * sign);
}
