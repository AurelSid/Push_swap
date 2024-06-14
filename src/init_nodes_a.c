/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:55:40 by asideris          #+#    #+#             */
/*   Updated: 2024/06/12 18:33:38 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_init_nodes_a(Node **a, Node **b)
{
	set_index(&*a);
	set_index(&*b);
	ft_set_targets_a(*a, *b);
	ft_set_stack_costs(*a,*b);
	ft_set_cheapest(**&a);
}
void	ft_set_targets_a(Node *a, Node *b)
{
	Node	*current_b;
	Node	*best_friend;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				best_friend = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->best_friend = ft_find_max(b);
		else
			a->best_friend = best_friend;
		a = a->next;
	}
}

void	ft_set_cheapest(Node *stack_top)
{
	long	cheapest_value;
	Node	*cheapest_node;

	if (!stack_top)
		return ;
	cheapest_value = LONG_MAX;
	while (stack_top)
	{
		if (stack_top->cost < cheapest_value)
		{
			cheapest_value = stack_top->cost;
			cheapest_node = stack_top;
		}
		stack_top = stack_top->next;
	}
	cheapest_node->cheapest = true;
}
