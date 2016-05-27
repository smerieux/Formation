/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:16:37 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/09 08:16:41 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_rt.h"

t_object			ft_parse(t_file **file, t_object new)
{
	ft_init_object(&new);
	*file = (*file)->next;
	if (!ft_strcmp((*file)->line, "name") && (*file = (*file)->next))
	{
		new.name = ft_strdup((*file)->line);
		*file = (*file)->next;
	}
	return (new);
}
