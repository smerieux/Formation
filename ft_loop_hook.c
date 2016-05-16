/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:48:16 by smerieux          #+#    #+#             */
/*   Updated: 2015/02/13 13:07:34 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_iso(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < TAB[1])
	{
		x = 0;
		while (x < TAB[0])
		{
			MAP[y][x].dx = ((0.75 * (MAP[y][x].x * TX) - 0.75 *
				MAP[y][x].y * TY) + env->width / 2.2) + CX;
			MAP[y][x].dy = (((0.75 / 2) * (MAP[y][x].x * TX) +
				(0.75 / 2) * (MAP[y][x].y * TY) - (MAP[y][x].z * TZ))
					+ env->height / 2.2) + CY;
			x += 1;
		}
		y += 1;
	}
}

void	ft_para(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < TAB[1])
	{
		x = 0;
		while (x < TAB[0])
		{
			MAP[y][x].dx = ((MAP[y][x].x * TX) + 0.75 * MAP[y][x].z)
				+ env->width / 2.2 + CX;
			MAP[y][x].dy = ((MAP[y][x].y * TY) + (0.75 / 2)
				* (MAP[y][x].z * TZ)) + env->height / 2.2 + CY;
			x += 1;
		}
		y += 1;
	}
}

void	ft_img_draw_pxl(t_env *env, int x, int y, int color)
{
	int	pxl;

	pxl = (y * env->size_line) + (x * (env->bpp / 8));
	if (x < env->width && y < env->height && x >= 0 && y >= 0 && pxl >= 0)
	{
		env->img[pxl] = color;
		env->img[pxl + 1] = color >> 8;
		env->img[pxl + 2] = color >> 16;
	}
}

void	ft_draw(t_env *env)
{
	env->p_img = mlx_new_image(env->mlx, env->width, env->height);
	env->img = mlx_get_data_addr(env->p_img, &env->bpp, &env->size_line,
				&env->endian);
	ft_draw_map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->p_img, 0, 0);
	mlx_destroy_image(env->mlx, env->p_img);
}

int		loop_hook(t_env *env)
{
	if (env->up == 1)
		ft_move_up(env);
	if (env->down == 1)
		ft_move_down(env);
	if (env->left == 1)
		ft_move_left(env);
	if (env->right == 1)
		ft_move_right(env);
	if (env->rez == 1)
		ft_move_reset(env);
	if (env->plus == 1)
		ft_zoom_in(env);
	if (env->minus == 1)
		ft_zoom_out(env);
	if (env->zero == 1)
		ft_zoom_reset(env);
	if (env->iso == 1)
		ft_iso(env);
	if (env->para == 1)
		ft_para(env);
	ft_draw(env);
	return (0);
}
