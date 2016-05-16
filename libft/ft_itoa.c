/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:54:47 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 16:49:52 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len += 1;
	}
	while (n != 0)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				len;
	unsigned int	nb;

	len = ft_intlen(n);
	if ((ret = (char *)malloc((len + 1) * sizeof(char))))
	{
		if (n < 0)
		{
			*ret = '-';
			nb = -n;
		}
		else
			nb = n;
		if (n == 0)
			*ret = '0';
		*(ret + len) = '\0';
		while (nb != 0)
		{
			*(ret + len - 1) = (char)('0' + (nb % 10));
			nb /= 10;
			len -= 1;
		}
	}
	return (ret);
}
