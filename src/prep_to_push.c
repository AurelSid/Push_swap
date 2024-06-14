/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_to_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:48:37 by asideris          #+#    #+#             */
/*   Updated: 2024/06/14 14:30:19 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

double	ft_get_median(struct Node *top)
{
	int			sum;
	double		result;
	double		i;
	int			j;
	struct Node	*current;

	i = 0;
	j = ft_listlen(top);
	sum = 0;
	result = 0;
	current = top->next;
	while (j > 0)
	{
		result = result + current->value;
		current = current->next;
		i++;
		j--;
	}
	result = result / i;
	return (result);
}
void	set_index(Node **stack)
{
	int	i;
	int	median;
	int j;
	Node *curr;
	
	i = 0;
	j = 0;

	curr = *stack;
	median = ft_listlen(**&stack) / 2;
	while (j < ft_listlen(**&stack))
	{
		curr->pos = i;
		if (i <= median)
			curr->over_middle = 1;
		else
			curr->over_middle = 0;
		curr = curr->next;
		i++;
		j++;
	}
}
