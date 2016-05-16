/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 17:42:52 by smerieux          #+#    #+#             */
/*   Updated: 2015/12/09 12:31:53 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

void		ft_getparams(int fd, char *line, t_env *env)
{
	char	**split;

	while (get_next_line(fd, &line) == 1)
	{
		if (J == 0)
		{
			split = ft_strsplit(line, ' ');
			while (split[J])
			{
				I = 0;
				while (split[J][I])
					I += 1;
				J += 1;
			}
			TAB[0] = J;
		}
		TAB[1] += 1;
	}
	env->data->nb = TAB[0] * TAB[1];
}

t_coor		**ft_init_tab(int nb, t_env *env)
{
	t_coor	**tab;
	t_coor	*tab2;
	int		i;

	i = 0;
	tab = (t_coor**)malloc(TAB[1] * sizeof(t_coor *));
	tab2 = (t_coor*)ft_memalloc(nb * sizeof(t_coor));
	while (i < TAB[1])
	{
		tab[i] = &tab2[i * TAB[0]];
		i += 1;
	}
	return (tab);
}

void		ft_parse(int fd, char **line, t_env *env)
{
	char	**split;
	int		x;
	int		y;

	MAP = ft_init_tab(env->data->nb, env);
	y = -1;
	while (get_next_line(fd, line) == 1)
	{
		split = ft_strsplit(*line, ' ');
		y += 1;
		x = 0;
		while (split[x])
		{
			MAP[y][x].x = x * CSTE;
			MAP[y][x].y = y * CSTE;
			MAP[y][x].z = ft_atoi(split[x]);
			x += 1;
		}
	}
}

void		ft_free(t_env *env)
{
	free(MAP[0]);
	free(MAP);
	free(env);
	MAP = NULL;
}

int			main(int argc, char **argv)
{
	int		fd;
	t_env	env;
	char	*line;
	char	*av;

	line = NULL;
	ft_usage(argc);
	av = ft_strdup(argv[1]);
	fd = ft_check_open(av);
	ft_init_coor(&env);
	ft_getparams(fd, line, &env);
	ft_check_close(fd);
	fd = ft_check_open(av);
	ft_parse(fd, &line, &env);
	ft_check_close(fd);
	ft_init_ptr(&env);
	mlx_hook(env.win, KP, KPM, which_key_press, &env);
	mlx_hook(env.win, KR, KRM, which_key_release, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	ft_free(&env);
	return (0);
}
