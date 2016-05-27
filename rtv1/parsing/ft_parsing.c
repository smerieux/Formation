/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:16:45 by smerieux          #+#    #+#             */
/*   Updated: 2016/05/27 10:54:09 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_rt.h"

static void			ft_get_material_light(t_file **file, t_object *new)
{
	*file = (*file)->next;
	new->material.diffuse = ft_atof((*file)->line);
	*file = (*file)->next;
	new->material.specular = ft_atof((*file)->line);
	*file = (*file)->next;
	new->material.shininess = ft_atof((*file)->line);
	*file = (*file)->next;
	new->material.transparent = ft_atof((*file)->line);
	*file = (*file)->next;
	new->material.reflective = ft_atof((*file)->line);
	*file = (*file)->next;
	new->material.refraction = ft_atof((*file)->line);
	*file = (*file)->next;
}

static void			ft_get_color(t_file **file, t_object *new)
{
	if (!ft_strcmp((*file)->line, "material"))
	{
		*file = (*file)->next;
		if (!ft_strcmp((*file)->line, "color"))
		{
			*file = (*file)->next;
			new->material.r = ft_atoh((*file)->line);
			*file = (*file)->next;
			new->material.g = ft_atoh((*file)->line);
			*file = (*file)->next;
			new->material.b = ft_atoh((*file)->line);
			*file = (*file)->next;
		}
		if (!ft_strcmp((*file)->line, "light"))
			ft_get_material_light(file, new);
	}
}

static void			ft_get_inter(t_file **file, t_object *new, int flag)
{
	if (flag == 1 && !ft_strcmp((*file)->line, "origin"))
	{
		*file = (*file)->next;
		new->pos.x = ft_atof((*file)->line);
		*file = (*file)->next;
		new->pos.y = ft_atof((*file)->line);
		*file = (*file)->next;
		new->pos.z = ft_atof((*file)->line);
		*file = (*file)->next;
	}
	else if (flag == 2 && !ft_strcmp((*file)->line, "rotation"))
	{
		*file = (*file)->next;
		new->axe.x = ft_atof((*file)->line);
		*file = (*file)->next;
		new->axe.y = ft_atof((*file)->line);
		*file = (*file)->next;
		new->axe.z = ft_atof((*file)->line);
		*file = (*file)->next;
	}
	else if (flag == 3 && (new->type = ft_strdup((*file)->line)))
	{
		*file = (*file)->next;
		new->misc = ft_atof((*file)->line);
	}
}

static t_object		ft_new_object(t_file **file)
{
	t_object	new;

	ft_init_object(&new);
	new = ft_parse(file, new);
	if (!ft_strcmp((*file)->line, "inter") && (*file = (*file)->next))
	{
		ft_get_inter(file, &new, 1);
		ft_get_inter(file, &new, 2);
		ft_get_inter(file, &new, 3);
		*file = (*file)->next;
		new.hyp = ft_atof((*file)->line);
		if (ft_check_float((*file)->line))
			*file = (*file)->next;
		if (ft_strcmp((*file)->line, "material"))
		{
			new.misc = ft_atof((*file)->line);
			*file = (*file)->next;
		}
	}
	ft_get_color(file, &new);
	return (new);
}

void				ft_parsing(t_file *file, t_data *d)
{
	t_file	*tmp;
	int		i;

	i = 0;
	d->nb_objects = 0;
	tmp = file;
	while (tmp)
	{
		if (ft_strcmp(tmp->line, "Object") == 0)
			d->nb_objects++;
		tmp = tmp->next;
	}
	if (d->nb_objects == 0)
	{
		ft_putendl_fd("No object", 2);
		exit(EXIT_FAILURE);
	}
	d->objects = (t_object *)malloc(sizeof(t_object) * d->nb_objects);
	while (file && ft_strcmp(file->line, "Light"))
	{
		if (ft_strcmp(file->line, "Object") == 0)
			d->objects[i++] = ft_new_object(&file);
		else
			file = file->next;
	}
}
