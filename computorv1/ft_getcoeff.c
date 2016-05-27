/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcoeff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:48:50 by smerieux          #+#    #+#             */
/*   Updated: 2015/07/04 12:58:06 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double	ft_getx0(char **grid, double x)
{
	int	i;

	i = -1;
	while (ft_strcmp(grid[++i], "=") != 0)
	{
		if (ft_strcmp(grid[i], "X^0") == 0)
		{
			if (grid[i - 2][0] == '-')
				x += ft_atof(grid[i - 2]);
			else
				x += ft_atof(grid[i - 2]);
		}
	}
	while (grid[i])
	{
		if (ft_strcmp(grid[i], "X^0") == 0)
		{
			if (grid[i - 2][0] == '-')
				x -= ft_atof(grid[i - 2]);
			else
				x -= ft_atof(grid[i - 2]);
		}
		i += 1;
	}
	return (x);
}

void	ft_initcat(char *cat, int j)
{
	cat[0] = 'X';
	cat[1] = '^';
	cat[2] = *ft_itoa(j);
	cat[3] = '\0';
}

double	ft_getxn_right(char **grid, double x, char *cat, int i)
{
	while (grid[i])
	{
		if (ft_strcmp(grid[i], cat) == 0)
		{
			if (ft_strcmp(grid[i - 3], "-") == 0)
				x += ft_atof(grid[i - 2]);
			else
				x -= ft_atof(grid[i - 2]);
		}
		i += 1;
	}
	return (x);
}

double	ft_getxn(char **grid, double x, int j)
{
	int		i;
	char	cat[4];

	i = 0;
	ft_initcat(cat, j);
	while (ft_strcmp(grid[i], "=") != 0)
	{
		if (ft_strcmp(grid[i], cat) == 0 && i == 2)
		{
			if (grid[i - 2][0] == '-')
				x += ft_atof(grid[i - 2]);
			else
				x += ft_atof(grid[i - 2]);
		}
		else if (ft_strcmp(grid[i], cat) == 0)
		{
			if (ft_strcmp(grid[i - 3], "-") == 0)
				x -= ft_atof(grid[i - 2]);
			else
				x += ft_atof(grid[i - 2]);
		}
		i += 1;
	}
	return (ft_getxn_right(grid, x, cat, i));
}

int		ft_getrank(char *str)
{
	int		rank;

	rank = 0;
	while (*str)
	{
		if (*str == '^')
			rank = rank < ft_atoi(str + 1) ? ft_atoi(str + 1) : rank;
		str += 1;
	}
	if (rank >= 10)
	{
		ft_putendl("rank 3 is already too much, so 10 or more...");
		return (0);
	}
	return (rank);
}
