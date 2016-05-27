/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:00:11 by smerieux          #+#    #+#             */
/*   Updated: 2015/07/02 17:31:26 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_solve_r0(double x)
{
	if (x == 0)
		ft_putendl("\033[1;32;40mThe solutions are infinite\033[0m");
	else
		ft_putendl("\033[1;32;40mThere is NO solution");
}

void	ft_solve_r2_detneg(double res, double det, double *x)
{
	det = det * -1;
	ft_putstr("\033[1;32;40mDiscriminant is strictly negative, \033[0m");
	ft_putendl("\033[1;32;40mthe two complex solutions are:\033[0m");
	res = (-x[1] / (2 * x[2]));
	ft_putstr(ft_dtoa(res));
	ft_putstr(" + i");
	res = (ft_sqrt(det) / (2 * x[2]));
	ft_putendl(ft_dtoa(res));
	res = (-x[1] / (2 * x[2]));
	ft_putstr(ft_dtoa(res));
	ft_putstr(" - i");
	res = (ft_sqrt(det) / (2 * x[2]));
	ft_putendl(ft_dtoa(res));
}

void	ft_solve_r2_detpos(double res, double det, double *x)
{
	res = (-x[1] - ft_sqrt(det)) / (2 * x[2]);
	ft_putstr("\033[1;32;40mDiscriminant is strictly positive, \033[0m");
	ft_putendl("\033[1;32;40mthe two solutions are:\033[0m");
	ft_putendl(ft_dtoa(res));
	res = (-x[1] + ft_sqrt(det)) / (2 * x[2]);
	ft_putendl(ft_dtoa(res));
}

void	ft_solve_r2_det0(double res, double *x)
{
	res = -x[1] / (2 * x[2]);
	ft_putstr("\033[1;32;40mDiscriminant is nul.\033[0m");
	ft_putendl("\033[1;32;40m The double solution is:\033[0m");
	ft_putendl(ft_dtoa(res));
}

void	ft_solve(int rank, double *x)
{
	double	res;
	double	det;

	res = 0;
	det = 0;
	if (rank == 0)
		ft_solve_r0(x[0]);
	else if (rank == 1)
	{
		ft_putendl("\033[1;32;40mThe solution is:\033[0m");
		res = -x[0] / x[1];
		ft_putendl(ft_dtoa(res));
	}
	else if (rank == 2)
	{
		det = x[1] * x[1] - (4 * x[2] * x[0]);
		ft_display_det(det);
		res = -x[0] / x[1];
		if (det == 0)
			ft_solve_r2_det0(res, x);
		if (det > 0)
			ft_solve_r2_detpos(res, det, x);
		if (det < 0)
			ft_solve_r2_detneg(res, det, x);
	}
}
