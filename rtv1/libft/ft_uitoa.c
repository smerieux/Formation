/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:09:28 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:09:41 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_len(unsigned long int n, unsigned int sys)
{
	int		j;

	j = 0;
	while (n >= sys)
	{
		n /= sys;
		j++;
	}
	return (j);
}

char		*ft_uitoa(unsigned long int n, unsigned int sys)
{
	char	*str;
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = ft_len(n, sys);
	str = ft_strnew(i + 1);
	str += i;
	while (i > 0 || n / sys > 0)
	{
		*str = base[(n % sys)];
		n /= sys;
		str--;
		i--;
	}
	*str = base[(n % sys)];
	return (str);
}
