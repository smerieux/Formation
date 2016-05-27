/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:58:28 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/11 10:53:40 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_strnbr(char const *s, char c)
{
	int	nb;

	nb = 0;
	while (s != NULL && *s)
	{
		while (*s && *s == c)
			s += 1;
		if (*s)
		{
			while (*s && *s != c)
				s += 1;
			nb += 1;
		}
	}
	return (nb);
}

static int		*ft_tabstrlen(char const *s, char c, int len)
{
	int	*tab;
	int	i;

	i = 0;
	if ((tab = (int*)ft_memalloc(sizeof(int) * len)) && s != NULL)
	{
		while (*s)
		{
			while (*s && *s == c)
				s += 1;
			while (*s && *s != c)
			{
				tab[i] += 1;
				s += 1;
			}
			i += 1;
		}
		tab[len] = 1;
	}
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		*lenstr;
	int		lentab;

	lentab = ft_strnbr(s, c);
	lenstr = ft_tabstrlen(s, c, lentab);
	if (!s || (tab = (char **)malloc((lentab + 1) *sizeof(char *))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			*tab = ft_strsub(s, 0, *lenstr);
			s += *lenstr;
			tab += 1;
			lenstr += 1;
		}
	}
	*tab = 0;
	free(lenstr - lentab);
	return (tab - lentab);
}
