/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 13:10:32 by smerieux          #+#    #+#             */
/*   Updated: 2015/02/13 12:40:28 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	wkp_bis(int keycode, t_env *env)
{
	if (keycode == PARA)
	{
		env->para = 1;
		env->iso = 0;
	}
	if (keycode == ISO)
	{
		env->iso = 1;
		env->para = 0;
	}
}

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
	if (keycode == REZ)
		env->rez = 1;
	if (keycode == PLUS)
		env->plus = 1;
	if (keycode == MINUS)
		env->minus = 1;
	if (keycode == ZERO)
		env->zero = 1;
	wkp_bis(keycode, env);
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
	if (keycode == REZ)
		env->rez = 0;
	if (keycode == PLUS)
		env->plus = 0;
	if (keycode == MINUS)
		env->minus = 0;
	if (keycode == ZERO)
		env->zero = 0;
	return (0);
}

void	ft_init_coor(t_env *env)
{
	env->data = (t_data*)malloc(sizeof(t_data));
	env->data->i = 0;
	env->data->j = 0;
	env->data->nb = 0;
	env->data->tab = (int*)ft_memalloc(2 * sizeof(int));
	env->data->map = NULL;
	env->iso = 1;
	env->para = 0;
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
	env->plus = 0;
	env->minus = 0;
	env->zero = 0;
	env->rez = 0;
	env->trans = (t_trans*)malloc(sizeof(t_trans));
	CX = 1;
	CY = 1;
	TX = 1;
	TY = 1;
	TZ = 1;
}

int		ft_init_ptr(t_env *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		return (-1);
	env->width = TAB[0] * CSTE < SWIDTH ? SWIDTH : LWIDTH;
	env->height = TAB[1] * CSTE < SHEIGHT ? SHEIGHT : LHEIGHT;
	if ((env->win = mlx_new_window(env->mlx, env->width, env->height, "Fdf"))
			== NULL)
		return (-1);
	return (0);
}
