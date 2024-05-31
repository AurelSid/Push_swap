/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:06 by asideris          #+#    #+#             */
/*   Updated: 2024/05/31 13:05:11 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

Node	*ft_find_smallest_cost(Node *stack_b_top)
{
	struct Node	*curr;
	struct Node	*min_node;
	int			j;
	int			min_val;

	j = 0;
	min_val = (stack_b_top)->cost + stack_b_top->best_friend->cost;
	curr = (stack_b_top)->next;
	min_node = stack_b_top;
	while (curr != stack_b_top)
	{
		if (curr->cost + stack_b_top->best_friend->cost < min_val)
		{
			min_val = curr->cost + curr->best_friend->cost;
			min_node = curr;
		}
		curr = curr->next;
		j--;
	}
	return (curr);
}

void	ft_set_to_top(Node **top, Node **node)
{
	int	i;

	i = (*node)->cost;
	while (i > 0)
	{
		if ((*node)->over_middle == 1)
			ra(top);
		else
			rra(top);
		i--;
	}
}
void	ft_push_cheapest(Node **stack_a_top, Node **stack_b_top)
{
	Node	*node;
	Node	*node_friend;

	node = ft_find_smallest_cost(**&stack_b_top);
	node_friend = node->best_friend;
	ft_set_to_top(*&stack_a_top, &node_friend);
	ft_set_to_top(*&stack_b_top, &node);
	pb(stack_b_top, stack_a_top);
}

void	ft_find_smallest_value(Node **stack_a_top)
{
	struct Node	*curr;
	struct Node	*min_node;
	int			j;
	int			min_val;

	j = 0;
	min_val = (*stack_a_top)->value + (*stack_a_top)->best_friend->value;
	curr = (*stack_a_top)->next;
	min_node = *stack_a_top;
	while (curr != *stack_a_top)
	{
		if (curr->value + (*stack_a_top)->best_friend->value < min_val)
		{
			min_val = curr->value + curr->best_friend->value;
			min_node = curr;
		}
		curr = curr->next;
		j--;
	}
	ft_set_to_top(*&stack_a_top, &min_node);
	
	printf("min node : %d", min_node->value);
}
