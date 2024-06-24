/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:13:08 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:47:47 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_find_min(t_node *stack)
{
	int		min_value;
	t_node	*min_t_node;
	t_node	*curr;

	curr = stack;
	min_value = stack->value;
	min_t_node = stack;
	while (curr)
	{
		if (curr->value < min_value)
		{
			min_value = curr->value;
			min_t_node = curr;
		}
		curr = curr->next;
	}
	return (min_t_node);
}

t_node	*ft_find_max(t_node *stack)
{
	int		max_value;
	t_node	*max_node;
	t_node	*curr;

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
