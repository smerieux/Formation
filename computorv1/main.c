/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:59:04 by smerieux          #+#    #+#             */
/*   Updated: 2015/07/03 16:00:49 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_display_det(double det)
{
	ft_putstr("\033[1;33;40mDelta =\033[0m ");
	ft_putstr(ft_dtoa(det));
	ft_putchar('\n');
}

void	ft_lets_solve(double *x, int rank)
{
	ft_reduce(x, rank);
	ft_display_rank(rank);
	ft_solve(rank, x);
}

void	ft_cant_solve(double *x, int rank)
{
	ft_reduce(x, rank);
	ft_display_rank(rank);
	ft_putstr("The polynomial degree is stricly greater than 2, ");
	ft_putendl("I can't solve.");
}

int		ft_compute(char *str)
{
	double	*x;
	char	**grid;
	int		rank;
	int		i;

	rank = ft_getrank(str);
	if (!(x = (double*)ft_memalloc((rank + 1) * sizeof(double))))
		return (-1);
	grid = ft_strsplit(str, ' ');
	if (!ft_check(grid))
		return (0);
	x[0] = ft_getx0(grid, x[0]);
	i = 1;
	while (i <= rank)
	{
		x[i] = ft_getxn(grid, x[i], i);
		i += 1;
	}
	rank = ft_ajust(rank, x);
	if (rank > 2)
		ft_cant_solve(x, rank);
	else
		ft_lets_solve(x, rank);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_compute(argv[1]) == -1)
			ft_putendl("Error: memory allocation failed");
	}
	return (0);
}
