/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:18:47 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:18:50 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

double		ft_vector_dot(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	new.z = a.z * b.z;
	return (new.x + new.y + new.z);
}

t_vector	ft_vector_add(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	return (new);
}

t_vector	ft_vector_sub(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = b.x - a.x;
	new.y = b.y - a.y;
	new.z = b.z - a.z;
	return (new);
}

t_vector	ft_vector_mult(t_vector a, double b)
{
	t_vector	new;

	new.x = a.x * b;
	new.y = a.y * b;
	new.z = a.z * b;
	return (new);
}

t_vector	ft_vector_wedge(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.y * b.z - a.z * b.y;
	new.y = a.z * b.x - a.x * b.z;
	new.z = a.x * b.y - a.y * b.x;
	return (new);
}
