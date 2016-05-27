/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:57:12 by smerieux          #+#    #+#             */
/*   Updated: 2015/07/03 14:52:44 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		ft_check(char **grid)
{
	int	i;
	int check;

	i = 0;
	check = 0;
	while (grid[i])
	{
		if (ft_strcmp(grid[i], "=") == 0)
			check = 1;
		i += 1;
	}
	if (check == 0)
	{
		ft_putendl("Equation not well formated");
		return (0);
	}
	return (1);
}

void	ft_reduce_bis(double *x, int rank, int i, int flag)
{
	while (i <= rank)
	{
		flag = 0;
		if (x[i] == 0)
			flag = 1;
		else if (x[i] < 0 && flag == 0)
		{
			write(1, "- ", 2);
			ft_putstr(ft_dtoa(x[i] * -1));
		}
		else if (x[i] > 0 && flag == 0)
		{
			write(1, "+ ", 2);
			ft_putstr(ft_dtoa(x[i]));
		}
		if (!flag)
		{
			ft_putstr(" * X^");
			ft_putnbr(i);
			write(1, " ", 1);
		}
		i += 1;
	}
}

void	ft_reduce(double *x, int rank)
{
	int	i;
	int	flag;

	ft_putstr("\033[1;34;40mReduced form: \033[0m");
	ft_putstr(ft_dtoa(x[0]));
	ft_putstr(" * X^0");
	write(1, " ", 1);
	i = 1;
	flag = 0;
	ft_reduce_bis(x, rank, i, flag);
	ft_putendl("= 0");
}

double	ft_sqrt(double x)
{
	double		min;
	double		max;
	double		c;

	min = 0;
	c = 0;
	max = (x > 1) ? x : 1;
	while ((max - min) > 0.0001)
	{
		c = (min + max) / 2;
		if (c * c > x)
			max = c;
		else
			min = c;
	}
	return (min);
}

void	ft_display_rank(int rank)
{
	ft_putstr("\033[1;31;40mPolynomial degree: \033[0m");
	ft_putnbr(rank);
	write(1, "\n", 1);
}
