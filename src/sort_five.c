/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:10:46 by asideris          #+#    #+#             */
/*   Updated: 2024/05/30 15:01:15 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_push_median(Node **top_a, Node **top_b)
{
	int	curr_median;

	while (ft_listlen(*top_a) > 5)
	{
		curr_median = ft_get_median(*top_a);
		if ((*top_a)->value < curr_median)
			pb(*&top_a, *&top_b);
		else
			ra(*&top_a);
	}
}

Node	*ft_find_smallest(Node *top_a)
{
	struct Node	*curr;
	struct Node	*min_node;
	int			j;
	int			min_val;

	j = 0;
	min_val = (top_a)->value;
	curr = (top_a)->next;
	min_node = top_a;
	while (curr != top_a)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_node = curr;
		}
		curr = curr->next;
		j--;
	}
	return (min_node);
}

void	ft_push_smallest(Node **top_a, Node **top_b)
{
	struct Node	*smallest;

	smallest = ft_find_smallest(&**top_a);
	while ((*top_a)->value != (smallest->value))
	{
		ra(*&top_a);
	}
	pb(*&top_a, *&top_b);
}
void	ft_sort_five(Node **top_a, Node **top_b)
{
	ft_push_median(*&top_a, *&top_b);
	ft_push_smallest(*&top_a, *&top_b);
	ft_push_smallest(*&top_a, *&top_b);
	ft_sort_three(&*top_a);
	pb(*&top_b, *&top_a);
	pb(*&top_b, *&top_a);
}
