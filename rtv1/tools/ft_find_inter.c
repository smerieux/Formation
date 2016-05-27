/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_inter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:17:54 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:17:56 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <libft.h>
#include "ft_rt.h"

const t_tab_obj		g_obj[6] =
{
	{"sphere", ft_sphere},
	{"plane", ft_plane},
	{"cone", ft_cone},
	{"cylinder", ft_cylinder},
	{"hyperboloid", ft_hyperboloid},
	{NULL, NULL}
};

double		ft_find_inter(t_data *d, int *i)
{
	int		k;
	int		save;
	double	alpha1;
	double	alpha2;

	alpha2 = HUGE_VAL;
	save = -1;
	while (++(*i) < d->nb_objects)
	{
		k = -1;
		while (g_obj[++k].type != NULL)
		{
			if (ft_strcmp(d->objects[*i].type, g_obj[k].type) == 0)
			{
				alpha1 = g_obj[k].func(d->objects[*i], d->cam.dir, d->cam.pos);
				if (alpha1 > 0.0 && (alpha1 < alpha2))
				{
					save = *i;
					alpha2 = alpha1;
				}
			}
		}
	}
	*i = save;
	return (alpha2);
}
