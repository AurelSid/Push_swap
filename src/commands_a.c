/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:46 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:04:29 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sa(t_node **top)
{
	t_node	*second;
	t_node	*first;
	t_node	*third;

	first = (*top);
	second = (*top)->next;
	third = second->next;
	(*top)->next = third;
	(*top)->prev = second;
	second->next = first;
	if (third != NULL)
		third->prev = first;
	(*top) = second;
	ft_printf("sa\n");
}

void	pa(t_node **a, t_node **b)
{
	t_node	*push_node;

	if (!*b)
		return ;
	push_node = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	push_node->prev = NULL;
	if (!*a)
	{
		*a = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *a;
		push_node->next->prev = push_node;
		*a = push_node;
	}
	ft_printf("pa\n");
}

void	ra(t_node **topa)
{
	t_node	*last_node;

	if (!*topa || !(*topa)->next)
		return ;
	last_node = ft_find_last(*topa);
	last_node->next = *topa;
	*topa = (*topa)->next;
	(*topa)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	ft_printf("ra\n");
}

void	rra(t_node **topa)
{
	t_node	*last;

	if (!*topa || !(*topa)->next)
		return ;
	last = ft_find_last(*topa);
	last->prev->next = NULL;
	last->next = *topa;
	last->prev = NULL;
	*topa = last;
	last->next->prev = last;
	ft_printf("rra\n");
}
