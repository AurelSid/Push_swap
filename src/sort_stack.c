/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:06:26 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:52:15 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (ft_listlen(*stack_a) > 3 && ft_check_sorted(*stack_a) == false)
		pb(*&stack_a, *&stack_b);
	if (ft_listlen(*stack_a) > 3 && ft_check_sorted(*stack_a) == false)
		pb(*&stack_a, *&stack_b);
	while (ft_listlen(*stack_a) > 3 && ft_check_sorted(*stack_a) == false)
	{
		ft_init_nodes_a(stack_a, stack_b);
		ft_push_a_to_b(&*stack_a, &*stack_b);
	}
	ft_sort_three(&*stack_a);
	while (*stack_b)
	{
		ft_init_nodes_b(stack_a, stack_b);
		ft_push_b_to_a(&*stack_a, &*stack_b);
	}
	set_index(*&stack_a);
}

void	ft_push_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;
	t_node	*curr_a;
	t_node	*curr_b;

	curr_a = *a;
	curr_b = *b;
	cheapest_node = ft_find_smallest_cost(*a);
	if (cheapest_node->over_middle == 1
		&& cheapest_node->best_friend->over_middle == 1)
	{
		while (*a != cheapest_node && *b != cheapest_node->best_friend)
		{
			ft_rot_both(a, b);
		}
	}
	else if (cheapest_node->over_middle == 0
		&& cheapest_node->best_friend->over_middle == 0)
	{
		while (*a != cheapest_node && *b != cheapest_node->best_friend)
			ft_rev_rot_both(a, b);
	}
	ft_set_to_top(a, &cheapest_node, 'a');
	ft_set_to_top(b, &cheapest_node->best_friend, 'b');
	pb(a, b);
}

void	ft_push_b_to_a(t_node **a, t_node **b)
{
	ft_set_to_top(a, (&(*b)->best_friend), 'a');
	pa(*&a, *&b);
}
