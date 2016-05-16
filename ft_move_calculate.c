/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:54:08 by smerieux          #+#    #+#             */
/*   Updated: 2015/02/12 13:31:30 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_up(t_env *env)
{
	CY -= 3;
}

void	ft_move_down(t_env *env)
{
	CY += 3;
}

void	ft_move_left(t_env *env)
{
	CX -= 3;
}

void	ft_move_right(t_env *env)
{
	CX += 3;
}

void	ft_move_reset(t_env *env)
{
	CX = 1;
	CY = 1;
}
