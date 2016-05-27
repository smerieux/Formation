/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:53:26 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/08 17:09:26 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_strwspace(const char *s);

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strwspace(s);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s += 1;
	ft_strncpy(ret, (const char *) s, len);
	return (ret);
}

static size_t	ft_strwspace(const char *s)
{
	size_t	a;
	size_t	b;
	size_t	i;

	a = 0;
	b = 0;
	i = 0;
	while (*s && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		a += 1;
		i += 1;
	}
	i = ft_strlen(s) - 1;
	if (a == ft_strlen(s))
		i = ft_strlen(s);
	while (*s && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		b += 1;
		i -= 1;
	}
	return (ft_strlen(s) - (a + b));
}
