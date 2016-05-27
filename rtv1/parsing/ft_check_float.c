/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:16:15 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:16:17 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_check_float(char *str)
{
	int		i;
	int		flag;
	int		p;

	i = 0;
	flag = 0;
	while (str && str[i] && ft_isspace(str[i]))
		i++;
	p = i;
	while (flag < 2 && str && str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			flag = 2;
		if (str[i] == '.')
			flag++;
		i++;
	}
	if (p == i - 1)
		return (0);
	return (1);
}
