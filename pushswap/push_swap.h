/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:43:39 by smerieux          #+#    #+#             */
/*   Updated: 2013/12/29 16:14:41 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <libft.h>

typedef struct		s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_data_list
{
	int				len;
	struct s_node	*begin;
	struct s_node	*end;
}					t_data_list;

t_node	*ft_create_node(void);
int		*ft_check_smaller(t_data_list *l);
int		ft_is_sorted(t_data_list *l_a);
void	ft_add_lst(t_data_list *data_list, int n);
void	ft_final_push(t_data_list *l_a, t_data_list *l_b, int *count);
void	ft_free_lst(t_data_list *data_list);
void	ft_sort_l_a(t_data_list *l_a, int *count);
void	ft_sort(t_data_list *l_a, t_data_list *l_b, int *count);
void	ft_sa(t_data_list *l_a, int ss);
void	ft_sb(t_data_list *l_b, int ss);
void	ft_ss(t_data_list *l_a, t_data_list *l_b);
void	ft_pa(t_data_list *l_a, t_data_list *l_b);
void	ft_pb(t_data_list *l_a, t_data_list *l_b);
void	ft_node_swap(t_node *node_a, t_node *node_b);
void	ft_push(t_data_list *l_1, t_data_list *l_2);
void	ft_push_bis(t_data_list *l_1, t_data_list *l_2);
void	ft_ra(t_data_list *l_a, int rr);
void	ft_rb(t_data_list *l_b, int rr);
void	ft_rr(t_data_list *l_a, t_data_list *l_b);
void	ft_rra(t_data_list *l_a, int rrr);
void	ft_rrb(t_data_list *l_a, int rrr);
void	ft_rrr(t_data_list *l_a, t_data_list *l_b);
void	ft_print_list(t_data_list *data_list);

#endif /* !PUSH_SWAP_H */
