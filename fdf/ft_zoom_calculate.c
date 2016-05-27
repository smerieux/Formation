/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 15:57:01 by smerieux          #+#    #+#             */
/*   Updated: 2015/02/11 14:59:52 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_in(t_env *env)
{
	TX += 0.5;
	TY += 0.5;
	TZ += 0.5;
}

void	ft_zoom_out(t_env *env)
{
	if (TX != 1)
	{
		TX -= 0.5;
		TY -= 0.5;
		TZ -= 0.5;
	}
}

void	ft_zoom_reset(t_env *env)
{
	if (TX != 1)
	{
		TX = 1;
		TY = 1;
		TZ = 1;
	}
}
