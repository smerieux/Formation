/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:48:16 by smerieux          #+#    #+#             */
/*   Updated: 2014/01/19 18:58:52 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

void	ft_draw(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	env->p_img = mlx_new_image(env->mlx, WIDTH , HEIGHT);
	env->img = mlx_get_data_addr(env->p_img, &env->bpp, &env->size_line, \
				   	&env->endian);
	while (x < WIDTH)
	{
		ft_ray_coor(env, x);
		ft_step_x_or_y(env);
		ft_check_hit_ray(env);
		ft_calculate(env);
		ft_draw_line(env, x, y);
		x += 1;
	}
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
		ft_rot_left(env);
	if (env->right == 1)
		ft_rot_right(env);
	ft_draw(env);
	return (0);
}
