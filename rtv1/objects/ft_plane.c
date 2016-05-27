/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:15:27 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:15:31 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

double		ft_plane(t_object obj, t_vector dir, t_vector o)
{
	double		a;
	double		b;
	double		alpha;

	obj.axe = ft_vector_normalize(obj.axe);
	a = ft_vector_dot(obj.axe, dir);
	if (a == 0)
		return (HUGE_VAL);
	else
	{
		b = ft_vector_dot(obj.axe, o) + obj.misc;
		alpha = -b / a;
		if (alpha > 0.02 && alpha < HUGE_VAL)
			return (alpha);
		else
			return (HUGE_VAL);
	}
}
