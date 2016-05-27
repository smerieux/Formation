/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:01:41 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:01:56 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

void	ft_coef_color(t_object obj, t_data *d, int i, t_vector n)
{
	double			diffuse;
	double			specular;

	diffuse = ft_diffuse_light(obj, d->lights[i], n);
	specular = ft_specular_light(obj, d->lights[i], n, d->cam.dir);
	d->r += diffuse * obj.material.r + specular * d->lights[i].rgb[0];
	d->g += diffuse * obj.material.g + specular * d->lights[i].rgb[1];
	d->b += diffuse * obj.material.b + specular * d->lights[i].rgb[2];
}

void	ft_color_normalize(t_data *d)
{
	if (d->r > 255)
		d->r = 255;
	if (d->g > 255)
		d->g = 255;
	if (d->b > 255)
		d->b = 255;
	if (d->r < 0)
		d->r = 0;
	if (d->g < 0)
		d->g = 0;
	if (d->b < 0)
		d->b = 0;
}
