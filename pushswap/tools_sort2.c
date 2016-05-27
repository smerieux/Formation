/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:59:23 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/29 16:14:53 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_check_smaller(t_data_list *l)
{
	int		i;
	int		*smaller;
	t_node	*tmp;

	i = 1;
	if ((smaller = (int *)ft_memalloc(2)))
	{
		if (l != NULL)
		{
			smaller[0] = l->begin->nb;
			tmp = l->begin;
			while (i <= l->len)
			{
				if (smaller[0] > tmp->nb)
				{
					smaller[0] = tmp->nb;
					smaller[1] = i;
				}
				tmp = tmp->next;
				i++;
			}
		}
	}
	return (smaller);
}

int		ft_is_sorted(t_data_list *l_a)
{
	t_node	*tmp;

	tmp = l_a->begin;
	while (tmp != l_a->end && tmp->nb < tmp->next->nb)
		tmp = tmp->next;
	if (tmp == l_a->end)
		return (1);
	return (0);
}

void	ft_final_push(t_data_list *l_a, t_data_list *l_b, int *count)
{
	while (l_b->len > 0)
	{
		ft_pa(l_a, l_b);
		if (l_b->len > 0)
			ft_putchar(' ');
		*count += 1;
	}
}

void	ft_sort_l_a(t_data_list *l_a, int *count)
{
	int	*min_a;

	min_a = ft_check_smaller(l_a);
	while (l_a->begin->nb != min_a[0])
	{
		if (min_a[1] > (l_a->len) / 2)
		{
			if (l_a->begin->nb - min_a[0] == 1)
				ft_sa(l_a, 0);
			else
				ft_rra(l_a, 0);
		}
		else
		{
			if (l_a->begin->nb - min_a[0] == 1)
				ft_sa(l_a, 0);
			else
				ft_ra(l_a, 0);
		}
		ft_putchar(' ');
		*count += 1;
	}
}

void	ft_sort(t_data_list *l_a, t_data_list *l_b, int *count)
{
	while (l_a->len > 0 && !ft_is_sorted(l_a))
	{
		ft_sort_l_a(l_a, count);
		if (!ft_is_sorted(l_a))
		{
			ft_pb(l_a, l_b);
			ft_putchar(' ');
			*count += 1;
		}
	}
	ft_final_push(l_a, l_b, count);
	ft_putchar('\n');
}
