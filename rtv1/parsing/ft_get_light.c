/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:16:23 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:16:34 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_rt.h"

static void		ft_init_light(t_light *new)
{
	new->pos.x = 0.0;
	new->pos.y = 0.0;
	new->pos.z = 0.0;
	new->dir.x = 0.0;
	new->dir.y = 0.0;
	new->dir.z = 0.0;
	new->coef = 0.0;
	new->rgb[0] = 0.0;
	new->rgb[1] = 0.0;
	new->rgb[2] = 0.0;
}

static void		ft_get_color(t_file **file, t_light *new)
{
	if (ft_strcmp((*file)->line, "color") == 0)
	{
		if (*file && (*file)->next)
		{
			*file = (*file)->next;
			new->rgb[0] = ft_atoh((*file)->line);
		}
		if (*file && (*file)->next)
		{
			*file = (*file)->next;
			new->rgb[1] = ft_atoh((*file)->line);
		}
		if (*file && (*file)->next)
		{
			*file = (*file)->next;
			new->rgb[2] = ft_atoh((*file)->line);
		}
	}
}

static t_light	ft_new_light(t_file **file)
{
	t_light	new;

	ft_init_light(&new);
	*file = (*file)->next;
	if (ft_strcmp((*file)->line, "origin") == 0)
	{
		*file = (*file)->next;
		new.pos.x = ft_atof((*file)->line);
		*file = (*file)->next;
		new.pos.y = ft_atof((*file)->line);
		*file = (*file)->next;
		new.pos.z = ft_atof((*file)->line);
		*file = (*file)->next;
	}
	if (ft_strcmp((*file)->line, "coefficient") == 0)
	{
		*file = (*file)->next;
		new.coef = ft_atof((*file)->line);
		*file = (*file)->next;
	}
	ft_get_color(file, &new);
	return (new);
}

void			ft_get_light(t_file *file, t_data *d)
{
	t_file	*tmp;
	int		i;

	i = 0;
	d->nb_lights = 0;
	tmp = file;
	while (tmp)
	{
		if (ft_strcmp(tmp->line, "Light") == 0)
			d->nb_lights++;
		tmp = tmp->next;
	}
	if (d->nb_lights)
		d->lights = (t_light *)malloc(sizeof(t_light) * d->nb_lights);
	while (file)
	{
		if (ft_strcmp(file->line, "Light") == 0)
			d->lights[i++] = ft_new_light(&file);
		else
			file = file->next;
	}
}
