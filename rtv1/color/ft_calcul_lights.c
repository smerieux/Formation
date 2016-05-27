/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_lights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:01:30 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:01:36 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rt.h"

double		ft_diffuse_light(t_object obj, t_light light, t_vector n)
{
	double		alpha;
	double		lambert;

	lambert = ft_vector_dot(light.dir, n);
	if (lambert < 0.0)
		lambert = 0.0;
	alpha = obj.material.diffuse * light.coef * lambert;
	return (alpha);
}

double		ft_specular_light(t_object o, t_light l, t_vector n, t_vector dir)
{
	t_vector	r;
	t_vector	tmp;
	double		phong;
	double		alpha;

	tmp = ft_vector_mult(n, ft_vector_dot(n, l.dir));
	tmp = ft_vector_mult(tmp, 2);
	r = ft_vector_sub(l.dir, tmp);
	r = ft_vector_normalize(r);
	phong = ft_vector_dot(dir, r);
	if (phong < 0.0)
		phong = 0.0;
	phong = pow(phong, 64);
	alpha = o.material.specular * l.coef * phong;
	return (alpha);
}
