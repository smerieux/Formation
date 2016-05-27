/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:04:03 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:10:00 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_search_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	else
		return (c - 55);
}

unsigned int	ft_atoh(const char *str)
{
	unsigned int	res;

	res = 0;
	if (!str || !*str)
		return (0);
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str && *str == '0')
		str++;
	if (*str && (*str == 'x' || *str == 'X'))
		str++;
	while (*str && ft_ishexa(*str))
		res = res * 16 + ft_search_value(*str++);
	return (res);
}
