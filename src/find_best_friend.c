/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_friend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:20:47 by asideris          #+#    #+#             */
/*   Updated: 2024/05/30 14:50:39 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>
#include <stdio.h>

void	ft_find_best_friend(Node **top_a, Node **node_b)
{
	Node	*curr;
	int		curr_result;
	int		min_result;

	curr = (*top_a);
	min_result = INT_MAX;
	while (1)
	{
		curr_result = curr->value - (*node_b)->value;
		if (curr_result > 0 && curr_result < min_result)
		{
			min_result = curr_result;
			(*node_b)->best_friend = curr;
			curr->best_friend = *node_b;
		}
		curr = curr->next;
		if (curr == *top_a)
			break ;
	}
}

void	ft_find_all_friends(Node **stack_a, Node **stack_b)
{
	Node	*curr;

	curr = (*stack_b);
	while (curr->next != *stack_b)
	{
		ft_find_best_friend(*&stack_a, &curr);
		curr = curr->next;
	}
	ft_find_best_friend(*&stack_a, &curr);
}
