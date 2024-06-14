/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:46 by asideris          #+#    #+#             */
/*   Updated: 2024/06/13 14:05:05 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sb(struct Node **top)
{
	struct Node	*second;
	struct Node	*first;
	struct Node	*third;

	first = (*top);
	second = (*top)->next;
	third = second->next;
	(*top)->next = third;
	(*top)->prev = second;
	second->next = first;
	if (third != NULL)
		third->prev = first;
	(*top) = second;
	ft_printf("sb\n");
}

void	pb(struct Node **a, struct Node **b)
{
	Node	*push_node;

	if (!*a)
		return ;
	push_node = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	push_node->prev = NULL;
	if (!*b)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->prev = push_node;
		*b = push_node;
	}
		ft_printf("pb\n");
}

void	rb(struct Node **topa)
{
	Node	*last_node;

	if (!*topa || !(*topa)->next)
		return ;
	last_node = ft_find_last(*topa);
	last_node->next = *topa;
	*topa = (*topa)->next;
	(*topa)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	ft_printf("rb\n");
}
void	rrb(struct Node **topa)
{
	{
		Node *last;

		if (!*topa || !(*topa)->next)
			return ;
		last = ft_find_last(*topa);
		last->prev->next = NULL;
		last->next = *topa;
		last->prev = NULL;
		*topa = last;
		last->next->prev = last;
	}

	ft_printf("rrb\n");
}