/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:08:25 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:08:35 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_word(char *str)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	return (word);
}

static int	ft_len_word(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

static char	*ft_get_str(char *str)
{
	char	*tmp;
	int		i;

	i = ft_len_word(str);
	tmp = (char *)malloc(sizeof(*tmp) * (i + 1));
	i = 0;
	while (*str && *str != ' ' && *str != '\t')
	{
		tmp[i] = *str;
		i++;
		str++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		**ft_strsplit_space(char *str)
{
	int		nb_word;
	int		i;
	char	**tab;

	i = -1;
	if (!str)
		return (NULL);
	nb_word = ft_count_word(str);
	tab = (char **)malloc(sizeof(char *) * (nb_word + 1));
	while (++i < nb_word)
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		tab[i] = ft_get_str(str);
		while (*str && *str != ' ' && *str != '\t')
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
