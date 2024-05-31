/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:06 by asideris          #+#    #+#             */
/*   Updated: 2024/05/30 17:15:47 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	find_cost(Node *top, Node *node)
{
	int	stack_center;
	int	pos;
	int	cost;

	pos = node->pos;
	cost = 0;
	stack_center = (ft_find_stack_center(top));
	if (pos <= stack_center)
	{
		cost = pos - 1;
		node->over_middle = 1;
	}
	else
	{
		cost = ((ft_listlen(node) - pos) + 1);
		node->over_middle = 0;
	}
	return (cost);
}

int	ft_find_stack_center(Node *stack)
{
	Node	*curr;

	curr = (stack);
	while (curr->next != stack)
	{
		curr = curr->next;
	}
	return (curr->pos / 2);
}
void	ft_set_stack_costs(Node **stack)
{
	Node	*curr_b;
	Node	*curr_a;

	curr_b = (*stack);
	curr_a = (*stack);
	while (curr_a->next != *stack)
	{
		curr_a->cost = find_cost(**&stack, curr_a);
		curr_a = curr_a->next;
	}
	curr_a->cost = find_cost(**&stack, curr_a);

}


