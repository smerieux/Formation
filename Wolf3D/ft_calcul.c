/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 13:18:49 by smerieux          #+#    #+#             */
/*   Updated: 2014/01/19 16:54:09 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include "wolf3d.h"

void		ft_ray_coor(t_env *env, int x)
{
	env->ray.win_x = 2 * x / (double)WIDTH - 1;
	env->ray.x_ray = env->coor.x_cam;
	env->ray.y_ray = env->coor.y_cam;
	env->ray.vec_x = env->coor.vec_x + env->coor.plan_x * env->ray.win_x;
	env->ray.vec_y = env->coor.vec_y + env->coor.plan_y * env->ray.win_x;
	env->ray.map_x = (int)env->ray.x_ray;
	env->ray.map_y = (int)env->ray.y_ray;
	env->ray.delta_x = sqrt(1 + (env->ray.vec_y * env->ray.vec_y) / \
						(env->ray.vec_x * env->ray.vec_x));
	env->ray.delta_y = sqrt(1 + (env->ray.vec_x * env->ray.vec_x) / \
						(env->ray.vec_y * env->ray.vec_y));
}

void		ft_step_x_or_y(t_env *env)
{
	if (env->ray.vec_x < 0)
	{
		env->ray.step_x = -1;
		env->ray.side_x = (env->ray.x_ray - env->ray.map_x) * env->ray.delta_x;
	}
	else
	{
		env->ray.step_x = 1;
		env->ray.side_x = (env->ray.map_x + 1.0 - env->ray.x_ray) *\
							 env->ray.delta_x;
	}
	if (env->ray.vec_y < 0)
	{
		env->ray.step_y = -1;
		env->ray.side_y = (env->ray.y_ray - env->ray.map_y) * env->ray.delta_y;
	}
	else
	{
		env->ray.step_y = 1;
		env->ray.side_y = (env->ray.map_y + 1.0 - env->ray.y_ray) *\
							 env->ray.delta_y;
	}
}

void		ft_check_hit_ray(t_env *env)
{
	env->ray.hit = 0;
	while (env->ray.hit == 0)
	{
		if (env->ray.side_x < env->ray.side_y)
		{
			env->ray.side_x += env->ray.delta_x;
			env->ray.map_x += env->ray.step_x;
			env->side = 0;
		}
		else
		{
			env->ray.side_y += env->ray.delta_y;
			env->ray.map_y += env->ray.step_y;
			env->side = 1;
		}
		if (env->map[env->ray.map_x][env->ray.map_y] > 0)
			env->ray.hit = 1;
	}
	if (env->side == 0)
		env->ray.wall_dist = fabs((env->ray.map_x - env->ray.x_ray + \
					(1 - env->ray.step_x) / 2) / env->ray.vec_x);
	else
		env->ray.wall_dist = fabs((env->ray.map_y - env->ray.y_ray + \
					(1 - env->ray.step_y) / 2) / env->ray.vec_y);
}

void		ft_calculate(t_env *env)
{
	env->ray.l_height = abs((int)(HEIGHT / env->ray.wall_dist));
	env->ray.d_start = (HEIGHT / 2) - (env->ray.l_height / 2);
	env->ray.d_end = env->ray.l_height / 2 + HEIGHT / 2;
	if (env->ray.d_start < 0)
		env->ray.d_start = 0;
	if (env->ray.d_end >= HEIGHT)
		env->ray.d_end = HEIGHT - 1;
}

void		ft_draw_line(t_env *env, int x, int y)
{
	while (y < HEIGHT)
	{
		if (y >= 0 && y < env->ray.d_start)
			ft_img_draw_pxl(env, x, y, 0xA9EAFE);
		if (y >= env->ray.d_start && y <= env->ray.d_end)
		{
			if (env->side == 0)
			{
				if (env->ray.vec_x > 0)
					ft_img_draw_pxl(env, x, y, 0x856D4D);
				else
					ft_img_draw_pxl(env, x, y, 0xF5F5DC);
			}
			else
			{
				if (env->ray.vec_y > 0)
					ft_img_draw_pxl(env, x, y, 0xFFF48D);
				else
					ft_img_draw_pxl(env, x, y, 0xCECECE);
			}
		}
		if (y > env->ray.d_end)
			ft_img_draw_pxl(env, x, y, 0xAFA77B);
		y += 1;
	}
}
