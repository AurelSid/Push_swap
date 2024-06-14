/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:13:08 by asideris          #+#    #+#             */
/*   Updated: 2024/06/11 17:44:41 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

Node	*ft_find_min(Node *stack)
{
	int min_value;
	Node *min_node;
	Node *curr;

	curr = stack;
	min_value = stack->value;
	min_node = stack;
	while (curr)
	{
		if (curr->value < min_value)
		{
			min_value = curr->value;
			min_node = curr;
		}
		curr = curr->next;
	}
	return (min_node);
}
Node	*ft_find_max(Node *stack)
{
	int max_value;
	Node *max_node;
	Node *curr;

	curr = stack;
	max_value = stack->value;
	max_node = stack;
	while (curr)
	{
		if (curr->value > max_value)
		{
			max_value = curr->value;
			max_node = curr;
		}
		curr = curr->next;
	}
	return (max_node);
}