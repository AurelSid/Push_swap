/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:56:12 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:47:53 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rot_both(t_node **a, t_node **b)
{
	t_node	*last_node_a;
	t_node	*last_node_b;

	if (!*a || !(*a)->next)
		return ;
	last_node_a = ft_find_last(*a);
	last_node_a->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node_a->next->prev = last_node_a;
	last_node_a->next->next = NULL;
	if (!*b || !(*b)->next)
		return ;
	last_node_b = ft_find_last(*b);
	last_node_b->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last_node_b->next->prev = last_node_b;
	last_node_b->next->next = NULL;
	ft_printf("rr\n");
}

void	ft_rev_rot_both(t_node **a, t_node **b)
{
	t_node	*last_b;
	t_node	*last_a;

	if (!*a || !(*a)->next)
		return ;
	last_a = ft_find_last(*a);
	last_a->prev->next = NULL;
	last_a->next = *a;
	last_a->prev = NULL;
	*a = last_a;
	last_a->next->prev = last_a;
	if (!*b || !(*b)->next)
		return ;
	last_b = ft_find_last(*b);
	last_b->prev->next = NULL;
	last_b->next = *b;
	last_b->prev = NULL;
	*b = last_b;
	last_b->next->prev = last_b;
	ft_printf("rrr\n");
}
