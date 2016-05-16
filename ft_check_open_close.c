/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_open_close.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 17:00:05 by smerieux          #+#    #+#             */
/*   Updated: 2015/02/10 14:52:00 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <stdlib.h>

int		ft_check_open(char *line)
{
	int	fd;

	if ((fd = open(line, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error open() failed", 2);
		exit (1);
	}
	return (fd);
}

void	ft_check_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_putendl_fd("Error close() failed", 2);
		exit (1);
	}
}

void	ft_usage(int argc)
{
	if (argc != 2)
	{
		ft_putstr("USAGE : [./fdf] [map]");
		ft_putchar('\n');
		exit (1);
	}
}
