/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:47:46 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/28 18:48:25 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_data_list *l_a, int rrr)
{
	if (l_a != NULL && l_a->len > 1)
	{
		l_a->begin = l_a->end;
		l_a->end = l_a->end->prev;
		if (!rrr)
			write(1, "rra", 3);
	}
}

void	ft_rrb(t_data_list *l_b, int rrr)
{
	if (l_b != NULL && l_b->len > 1)
	{
		l_b->begin = l_b->end;
		l_b->end = l_b->end->prev;
		if (!rrr)
			write(1, "rrb", 3);
	}
}

void	ft_rr(t_data_list *l_a, t_data_list *l_b)
{
	ft_ra(l_a, 1);
	ft_rb(l_b, 1);
	write(1, "rr", 2);
}

void	ft_ra(t_data_list *l_a, int rr)
{
	if (l_a != NULL && l_a->len > 1)
	{
		l_a->end = l_a->begin;
		l_a->begin = l_a->end->next;
		if (!rr)
			write(1, "ra", 2);
	}
}

void	ft_rb(t_data_list *l_b, int rr)
{
	if (l_b != NULL && l_b->len > 0)
	{
		l_b->end = l_b->begin;
		l_b->begin = l_b->end->next;
		if (!rr)
			write(1, "rb", 2);
	}
}
