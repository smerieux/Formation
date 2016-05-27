/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:17:42 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:17:45 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_rt.h"

void	ft_destroy_data(t_data *d)
{
	t_object	*obj;
	int			i;

	obj = d->objects;
	i = -1;
	while (++i < d->nb_objects)
	{
		free(obj[i].name);
		free(obj[i].type);
	}
	free(obj);
	if (d->nb_lights)
		free(d->lights);
}
