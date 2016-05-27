/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 21:22:05 by alebourg          #+#    #+#             */
/*   Updated: 2014/01/19 17:29:01 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_data_list
{
	struct s_data_list	*next;
	struct s_data_list	*next_str;
	int				fd;
	int				rd;
	int				begin;
	int				begin_save;
	char			str[BUFF_SIZE];
}					d_list;

d_list		*search_fd(int fd, int rd, d_list *stat, char opt);
int			save_files(int fd, d_list *save, int first);
int			free_lst(d_list *save, d_list *stat, d_list *tmp, char ret);
void		cp_line(d_list *save, char **line, int *size_line, char write);
int			get_next_line(int const fd, char **line);

#endif		/* !GET_NEXT_LINE_H */
