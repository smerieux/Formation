/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 13:18:49 by smerieux          #+#    #+#             */
/*   Updated: 2015/02/13 14:23:03 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	ft_line(t_coor pt0, t_coor pt1, t_env *env)
{
	int	err;

	env->dx = abs(pt1.dx - pt0.dx);
	env->sx = pt0.dx < pt1.dx ? 1 : -1;
	env->dy = abs(pt1.dy - pt0.dy);
	env->sy = pt0.dy < pt1.dy ? 1 : -1;
	err = env->dx > env->dy ? env->dx : -env->dy;
	while (pt0.dx != pt1.dx && pt0.dy != pt1.dy)
	{
		ft_img_draw_pxl(env, pt0.dx, pt0.dy, 0xFFB907);
		env->e2 = err;
		if (env->e2 > -env->dx)
		{
			err -= env->dy;
			pt0.dx += env->sx;
		}
		if (env->e2 < env->dy)
		{
			err += env->dx;
			pt0.dy += env->sy;
		}
	}
	ft_img_draw_pxl(env, pt0.dx, pt0.dy, 0xFFB907);
}

void	ft_line_h(t_coor pt0, t_coor pt1, t_env *env)
{
	int	a;

	a = pt0.dx < pt1.dx ? 1 : -1;
	while (pt0.dx != pt1.dx)
	{
		ft_img_draw_pxl(env, pt0.dx, pt0.dy, 0xBEBBBB);
		pt0.dx += a;
	}
}

void	ft_line_v(t_coor pt0, t_coor pt1, t_env *env)
{
	int	a;

	a = pt0.dy < pt1.dy ? 1 : -1;
	while (pt0.dy != pt1.dy)
	{
		ft_img_draw_pxl(env, pt0.dx, pt0.dy, 0xBEBBBB);
		pt0.dy += a;
	}
}

void	ft_draw_h(t_env *env)
{
	I = 0;
	while (I < TAB[1])
	{
		J = 0;
		while (J < TAB[0] - 1)
		{
			if (MAP[I][J].dy == MAP[I][J + 1].dy)
				ft_line_h(MAP[I][J], MAP[I][J + 1], env);
			else
				ft_line(MAP[I][J], MAP[I][J + 1], env);
			J += 1;
		}
		I += 1;
	}
}

void	ft_draw_map(t_env *env)
{
	ft_draw_h(env);
	I = 0;
	while (I < TAB[1] - 1)
	{
		J = 0;
		while (J < TAB[0])
		{
			if (MAP[I][J].dx == MAP[I + 1][J].dx)
				ft_line_v(MAP[I][J], MAP[I + 1][J], env);
			else
				ft_line(MAP[I][J], MAP[I + 1][J], env);
			J += 1;
		}
		I += 1;
	}
}
