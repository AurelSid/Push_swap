/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:54:46 by asideris          #+#    #+#             */
/*   Updated: 2024/06/12 17:30:18 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_nodes_b(Node **a, Node **b)
{
	set_index(&*a);
	set_index(&*b);
	ft_set_targets_b(*a, *b);
}

void	ft_set_targets_b(Node *a, Node *b)
{
	Node	*current_a;
	Node	*best_friend;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				best_friend = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->best_friend = ft_find_min(a);
		else
			b->best_friend = best_friend;
		b = b->next;
	}
}
