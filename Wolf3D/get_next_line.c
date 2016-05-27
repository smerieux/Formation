/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 10:08:30 by alebourg          #+#    #+#             */
/*   Updated: 2014/01/09 17:41:31 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

d_list		*search_fd(int fd, int rd, d_list *stat, char opt)
{
	d_list	*new;

	while (stat && opt == 0 && stat->fd != fd && stat->next != NULL)
		stat = stat->next;
	if (stat && opt == 0 && stat->fd == fd)
		return (stat);
	if ((new = (d_list*)malloc(sizeof(d_list))) == NULL)
		return (NULL);
	new->next = NULL;
	new->next_str = NULL;
	new->rd = rd;
	new->fd = fd;
	new->str[0] = 0;
	new->begin = 0;
	new->begin_save = 0;
	if (stat == NULL)
	{
		stat = new;
		return (stat);
	}
	if (opt == 1)
		stat->next_str = new;
	else
		stat->next = new;
	return (new);
}

int			save_files(int fd, d_list *save, int first)
{
	d_list		*curent;
	int			rd;
	int			i;
	char		str[BUFF_SIZE];

	while (save->next != NULL && save->fd != fd)
		save = save->next;
	if (save->fd != fd || first == 1)
	{
		curent = save;
		while ((rd = read(fd, str, BUFF_SIZE)) != 0)
		{
			if (rd < 0)
				return (rd);
			curent = search_fd(fd, rd, curent, 1);
			i = 0;
			while (i != rd)
			{
				curent->str[i] = str[i];
				i = i + 1;
			}
			curent->str[rd] = 0;
		}
	}
	return (0);
}

int			free_lst(d_list *save, d_list *stat, d_list *tmp, char ret)
{
	if (save->next_str != NULL)
		ret = 1;
	tmp = save;
	while (tmp->next_str)
	{
		tmp = tmp->next_str;
		if (tmp->begin == tmp->rd)
		{
			save->next_str = tmp->next_str;
			free(tmp);
			tmp = save;
		}
	}
	tmp = stat;
	while (tmp && save->next_str == NULL)
	{
		if (tmp->next == save)
		{
			tmp->next = save->next;
			free(save);
		}
		tmp = tmp->next;
	}
	return (ret);
}

void		cp_line(d_list *save, char **line, int *size_line, char write)
{
	int		stop;

	stop = 0;
	*size_line = 0;
	while (save->next_str && stop != 1)
	{
		save = save->next_str;
		if (write > 0)
			save->begin = save->begin_save;
		else
			save->begin_save = save->begin;
		while (save->begin != save->rd && save->str[save->begin] != '\n')
		{
			if (write > 0)
				(*line)[*size_line] = save->str[save->begin];
			*size_line = *size_line + 1;
			save->begin = save->begin + 1;
		}
		if (save->str[save->begin] == '\n')
		{
			save->begin = save->begin + 1;
			stop = 1;
		}
	}
}

int			get_next_line(int const fd, char **line)
{
	static d_list	*stat = NULL;
	d_list			*save;
	d_list			*tmp;
	int				size_line;
	char			ret;

	ret = 0;
	tmp = NULL;
	if (fd < 0)
		return (-1);
	if (stat == NULL)
		stat = search_fd(-10, -10, stat, 0);
	save = search_fd(fd, -10, stat, 0);
	if ((save_files(fd, save, 1)) < 0)
		return (-1);
	cp_line(save, line, &size_line, 0);
	if (line != NULL && *line != NULL)
		free(*line);
	*line = NULL;
	if (((*line) = (char*)malloc(sizeof(char) * size_line + 1)) == NULL)
		return (-1);
	(*line)[size_line] = '\0';
	cp_line(save, line, &size_line, 1);
	return (free_lst(save, stat, tmp, ret));
}
