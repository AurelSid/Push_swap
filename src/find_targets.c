/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:14:38 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:46:47 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*best_friend;
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
		a->best_friend = best_friend;
		a = a->next;
	}
}
