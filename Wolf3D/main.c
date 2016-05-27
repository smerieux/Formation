/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 17:42:52 by smerieux          #+#    #+#             */
/*   Updated: 2014/01/19 18:54:11 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include "get_next_line.h"
#include "wolf3d.h"

int		*ft_getparams(int fd)
{
	int		*tab_params;
	int		ret;
	int		count;
	char	*line;

	count = 1;
	line = NULL;
	ret = 0;
	tab_params = (int*)ft_memalloc(2 * sizeof(int));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == 1 && count == 1)
		{
			tab_params[0] = ft_strlen(line);
			count += 1;
		}
		tab_params[1] += 1;
	}
	return (tab_params);
}

int		**ft_init_tab(int col, int line)
{
	int	**tab;
	int	*tab2;
	int	i;

	i = 0;
	tab = (int**) malloc(line * sizeof(int *));
	tab2 = (int*) ft_memalloc((col * line) *sizeof(int));
	while (i < line)
	{
		tab[i] = &tab2[i * col];
		i += 1;
	}
	return (tab);
}

int		**ft_parse(int fd, int *tab_params)
{
	int		**map;
	int		i;
	int		j;
	char	*line;

	j = 0;
	line = (char*)malloc(sizeof(char) * (tab_params[0] + 1));
	map = ft_init_tab(tab_params[0], tab_params[1]);
	while (j < tab_params[1])
	{
		i = 0;
		read(fd, line, (tab_params[0] + 1));
		while (line[i] != '\n')
		{
			map[j][i] = line[i] - 48;
			i += 1;
		}
		j += 1;
	}
	return (map);
}

void	ft_freetab(int **tab)
{
	free(tab[0]);
	free(tab);
	tab = NULL;
}

int		main(int argc, char **argv)
{
	int		fd;
	int		*tab;
	int		ret;
	t_env	env;

	if (argc != 2 || (ret = ft_strcmp(argv[1], "map")) != 0)
	{
		ft_putstr("Usage : [./wolf3d] [map]");
		ft_putchar('\n');
		exit(1);
	}
	fd = ft_check_open();
	tab = ft_getparams(fd);
	ft_check_close(fd);
	fd = ft_check_open();
	env.map = ft_parse(fd, tab);
	ft_check_close(fd);
	ft_init_coor(&env);
	ft_init_ptr(&env);
	mlx_hook(env.win, KP, KPM, which_key_press, &env);
	mlx_hook(env.win, KR, KRM, which_key_release, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	ft_freetab(env.map);
	return (0);
}
