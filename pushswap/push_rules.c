/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:37:38 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/28 18:40:05 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data_list *l_a, int ss)
{
	if (l_a != NULL && l_a->len > 1)
	{
		ft_node_swap(l_a->begin, l_a->begin->next);
		if (!ss)
			write(1, "sa", 2);
	}
}

void	ft_sb(t_data_list *l_b, int ss)
{
	if (l_b != NULL && l_b->len > 1)
	{
		ft_node_swap(l_b->begin, l_b->begin->next);
		if (!ss)
			write(1, "sb", 2);
	}
}

void	ft_ss(t_data_list *l_a, t_data_list *l_b)
{
	ft_sa(l_a, 1);
	ft_sb(l_b, 1);
	write(1, "ss", 2);
}

void	ft_pa(t_data_list *l_a, t_data_list *l_b)
{
	if (l_b != NULL && l_b->len > 0)
	{
		if (l_b->len == 1)
		{
			ft_push(l_b, l_a);
			l_b->len = 0;
			l_b->begin = NULL;
			l_b->end = NULL;
		}
		else
			ft_push(l_b, l_a);
		write(1, "pa", 2);
	}
}

void	ft_pb(t_data_list *l_a, t_data_list *l_b)
{
	if (l_a != NULL && l_a->len > 0)
	{
		if (l_a->len == 1)
		{
			ft_push(l_a, l_b);
			l_a->len = 0;
			l_a->begin = NULL;
			l_a->end = NULL;
		}
		else
			ft_push(l_a, l_b);
		write(1, "pb", 2);
	}
}
