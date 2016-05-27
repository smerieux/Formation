/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 08:18:16 by smerieux          #+#    #+#             */
/*   Updated: 2016/02/10 10:27:49 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_rt.h"

static int		ft_key_hook(int keycode, t_data *d)
{
	if (keycode == 0x35)
	{
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->win);
		ft_destroy_data(d);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

static void		ft_get_data(t_data *d)
{
	int		bpp;
	int		sizeline;
	int		endian;

	d->data = mlx_get_data_addr(d->img, &bpp, &sizeline, &endian);
	d->bpp = bpp;
	d->sizeline = sizeline;
	d->endian = endian;
}

static int		ft_expose_hook(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

static void		ft_free_file(t_file *tmp)
{
	t_file *ptr;

	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr->line);
		free(ptr);
	}
}

int				main(int argc, char **argv)
{
	t_data	d;
	t_file	*file;
	t_file	*tmp;

	file = NULL;
	if (argc != 2)
		ft_putendl_fd("Usage: ./rtv1 scene", 2);
	else
	{
		tmp = ft_init(&file, &d, argv[1]);
		ft_parsing(file, &d);
		ft_get_light(file, &d);
		if ((d.mlx = mlx_init()) == NULL)
			return (-1);
		if ((d.win = mlx_new_window(d.mlx, d.width, d.height, "RTV1")) == NULL)
			return (-1);
		d.img = mlx_new_image(d.mlx, d.width, d.height);
		ft_get_data(&d);
		ft_free_file(tmp);
		ft_raytracing(&d);
		mlx_key_hook(d.win, &ft_key_hook, &d);
		mlx_expose_hook(d.win, ft_expose_hook, &d);
		mlx_loop(d.mlx);
	}
	return (0);
}
