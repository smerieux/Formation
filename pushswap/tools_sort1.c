/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:49:05 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/28 19:03:19 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_swap(t_node *node_a, t_node *node_b)
{
	int	tmp;

	tmp = node_a->nb;
	node_a->nb = node_b->nb;
	node_b->nb = tmp;
}

void	ft_rrr(t_data_list *l_a, t_data_list *l_b)
{
	ft_rra(l_a, 1);
	ft_rrb(l_b, 1);
	write(1, "rrr", 3);
}

void	ft_push_bis(t_data_list *l_1, t_data_list *l_2)
{
	t_node	*tmp;

	if (l_2->len > 0)
	{
		tmp = l_2->begin;
		l_2->begin = l_1->begin;
		l_2->begin->next = tmp;
		l_2->begin->prev = l_2->end;
		l_2->end->next = l_2->begin;
		tmp->prev = l_2->begin;
	}
	else
	{
		l_2->begin = l_1->begin;
		l_2->end = l_1->begin;
		l_2->begin->next = l_1->begin;
		l_2->begin->prev = l_1->begin;
	}
}

void	ft_push(t_data_list *l_1, t_data_list *l_2)
{
	t_node	*tmp;

	if (l_1 != NULL && l_2 != NULL && l_1->len > 0 && (tmp = l_1->begin->next))
	{
		ft_push_bis(l_1, l_2);
		if (l_1->len > 1)
		{
			l_1->begin = tmp;
			l_1->begin->prev = l_1->end;
			l_1->end->next = tmp;
		}
		l_2->len = l_2->len + 1;
		l_1->len = l_1->len - 1;
	}
}
