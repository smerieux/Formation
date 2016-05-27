/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:41:24 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/29 16:41:21 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_node		*ft_create_node(void)
{
	t_node	*new;

	new = (t_node *)ft_memalloc(sizeof(t_node));
	if (!new)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	new->nb = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_add_lst(t_data_list *data_list, int n)
{
	t_node	*tmp;

	if (data_list != NULL)
	{
		if (data_list->len == 0)
		{
			data_list->len = data_list->len + 1;
			data_list->begin = ft_create_node();
			data_list->end = data_list->begin;
			data_list->begin->nb = n;
			data_list->begin->next = data_list->begin;
			data_list->begin->prev = data_list->begin;
		}
		else
		{
			tmp = data_list->end;
			data_list->len = data_list->len + 1;
			data_list->end = ft_create_node();
			data_list->end->nb = n;
			data_list->end->next = data_list->begin;
			data_list->end->prev = tmp;
			tmp->next = data_list->end;
			data_list->begin->prev = data_list->end;
		}
	}
}

void		ft_free_lst(t_data_list *data_list)
{
	t_node	*tmp;
	t_node	*del;

	if (data_list)
	{
		tmp = data_list->begin;
		while (data_list->len > 0)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
			data_list->len = data_list->len - 1;
		}
		data_list = NULL;
	}
}

void		ft_print_list(t_data_list *data_list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = data_list->begin;
	while (i < data_list->len)
	{
		ft_putnbr(tmp->nb);
		ft_putchar(' ');
		tmp = tmp->next;
		i += 1;
	}
	if (i == data_list->len)
		ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	t_data_list		l_a;
	t_data_list		l_b;
	int				i;
	static int		count;

	i = 1;
	l_a.len = 0;
	l_b.len = 0;
	count = 0;
	if (argc <= 1)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	while (argc > 1 && i < argc)
		ft_add_lst(&l_a, (ft_atoi(argv[i++])));
	ft_sort(&l_a, &l_b, &count);
	ft_free_lst(&l_a);
	return (0);
}
