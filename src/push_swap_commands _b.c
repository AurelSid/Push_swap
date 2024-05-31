/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands _b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:46 by asideris          #+#    #+#             */
/*   Updated: 2024/05/31 14:20:09 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sa(struct Node **top)
{
	struct Node	*second;
	struct Node	*first;
	struct Node	*last;

	last = (*top)->prev;
	first = (*top);
	second = (*top)->next;
	(*top)->next = second->next;
	(*top)->prev = second;
	second->next = (*top);
	second->prev = last;
	last->next = second;
	(*top) = second;
	// printf("+++ swapped first with econd +++\n");
}

void	pb(struct Node **topa, struct Node **topb)
{
	struct Node	*first;
	struct Node	*second;
	struct Node	*last;

	first = *topa;
	last = first->prev;
	second = first->next;
	ft_push_node(&*topb, (*topa)->value);
	(*topa) = second;
	second->prev = last;
	last->next = second;
}

void	ra(struct Node **topa)
{
	struct Node	*second;

	second = (*topa)->next;
	*topa = second;
}
void	rra(struct Node **topa)
{
	struct Node *first;
	struct Node *last;

	// printf("List length : %d \n", ft_listlen(*topa));
	first = *topa;
	last = (*topa)->prev;
	first->prev = last;
	*topa = last;
}