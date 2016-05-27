/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:14:55 by smerieux          #+#    #+#             */
/*   Updated: 2016/01/11 11:02:49 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (*str == 9 || *str == 10 || *str == 11 || *str == 12 || *str == 13\
			|| *str == 32)
		str += 1;
	if (*str == '-' || *str == '+')
		str += 1;
	if (ft_isdigit((int)str[i]) == 1)
	{
		while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		{
			nb = nb * 10 + (str[i] - '0');
			i += 1;
		}
	}
	else
		return (0);
	if (*(str - 1) == '-')
		nb = -nb;
	return (nb);
}
