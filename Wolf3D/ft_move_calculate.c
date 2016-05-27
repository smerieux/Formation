/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:54:08 by smerieux          #+#    #+#             */
/*   Updated: 2014/01/19 14:28:31 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include "wolf3d.h"

void	ft_move_up(t_env *env)
{
	if (env->up == 1)
	{
		if (env->map[(int)(env->coor.x_cam + env->coor.vec_x * MOVE)]\
				[(int)(env->coor.y_cam)] == 0)
			env->coor.x_cam += env->coor.vec_x * MOVE;
		if (env->map[(int)(env->coor.x_cam)][(int)(env->coor.y_cam \
				+ env->coor.vec_y * MOVE)] == 0)
			env->coor.y_cam += env->coor.vec_y * MOVE;
	}
}

void	ft_move_down(t_env *env)
{
	if (env->down == 1)
	{
		if (env->map[(int)(env->coor.x_cam - env->coor.vec_x * MOVE)]\
				[(int)(env->coor.y_cam)] == 0)
			env->coor.x_cam -= env->coor.vec_x * MOVE;
		if (env->map[(int)(env->coor.x_cam)][(int)(env->coor.y_cam \
				- env->coor.vec_y * MOVE)] == 0)
			env->coor.y_cam -= env->coor.vec_y * MOVE;
	}
}

void	ft_rot_right(t_env *env)
{
	double	oldvec_x;
	double	oldplan_x;

	oldplan_x = env->coor.plan_x;
	oldvec_x = env->coor.vec_x;
	if (env->right == 1)
	{
		env->coor.vec_x = env->coor.vec_x * cos(-ROT) - env->coor.vec_y * sin\
						  (-ROT);
		env->coor.vec_y = oldvec_x * sin(-ROT) + env->coor.vec_y * cos\
						  (-ROT);
		env->coor.plan_x = env->coor.plan_x * cos(-ROT) - env->coor.plan_y * \
						   sin(-ROT);
		env->coor.plan_y = oldplan_x * sin(-ROT) + env->coor.plan_y * \
						   cos(-ROT);
	}
}

void	ft_rot_left(t_env *env)
{
	double	oldvec_x;
	double	oldplan_x;

	oldplan_x = env->coor.plan_x;
	oldvec_x = env->coor.vec_x;
	if (env->left == 1)
	{
		env->coor.vec_x = env->coor.vec_x * cos(ROT) - env->coor.vec_y * sin\
						  (ROT);
		env->coor.vec_y = oldvec_x * sin(ROT) + env->coor.vec_y * cos\
						  (ROT);
		env->coor.plan_x = env->coor.plan_x * cos(ROT) - env->coor.plan_y * \
						   sin(ROT);
		env->coor.plan_y = oldplan_x * sin(ROT) + env->coor.plan_y * \
						   cos(ROT);
	}
}
