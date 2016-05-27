/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 13:10:32 by smerieux          #+#    #+#             */
/*   Updated: 2014/01/19 19:05:42 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "wolf3d.h"

int		which_key_press(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == UP)
		env->up = 1;
	if (keycode == DOWN)
		env->down = 1;
	if (keycode == LEFT)
		env->left = 1;
	if (keycode == RIGHT)
		env->right = 1;
	return (0);
}

int		which_key_release(int keycode, t_env *env)
{

	if (keycode == UP)
		env->up = 0;
	if (keycode == DOWN)
		env->down = 0;
	if (keycode == LEFT)
		env->left = 0;
	if (keycode == RIGHT)
		env->right = 0;
	return (0);
}

void	ft_init_coor(t_env *env)
{
	env->coor.x_cam = 7;
	env->coor.y_cam = 15;
	env->coor.vec_x = -1;
	env->coor.vec_y = 0;
	env->coor.plan_x = 0;
	env->coor.plan_y = 0.66;
	env->ray.hit = 0;
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
}

void	ft_img_draw_pxl(t_env *env, int x, int y, int color)
{
	int	pxl;

	pxl = y * env->size_line + x * (env->bpp / 8);
	env->img[pxl] = color;
	env->img[pxl + 1] = color >> 8;
	env->img[pxl + 2] = color >> 16;
}

int		ft_init_ptr(t_env *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		return (-1);
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D")) == NULL)
		return (-1);
	return (0);
}
