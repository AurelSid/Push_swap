/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:14 by asideris          #+#    #+#             */
/*   Updated: 2024/05/31 13:28:53 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	ft_listlen(struct Node *lst)
{
	int			i;
	struct Node	*current;

	if (!lst)
		return (0);
	current = lst;
	i = 1;
	current = current->next;
	while (current != lst)
	{
		current = current->next;
		i++;
	}
	return (i);
}
void	ft_print_list(struct Node *lst)
{
	struct Node	*tmp;

	if (lst == NULL)
	{
		printf("List is empty\n");
		return ;
	}
	tmp = lst;
	do
	{
		printf("node: %-8d	pos: %.1d		best friend: %.1d		cost: %.1d over middle: %.1d\n", tmp->value, tmp->pos,
			tmp->best_friend->value,tmp->cost, tmp->over_middle);
		tmp = tmp->next;
	} while (tmp != lst);
	printf("\n");
}
int	ft_get_median(struct Node *top)
{
	int			sum;
	double		result;
	int			i;
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
	// printf("stack median : %f\n", result);
	return (result);
}
void	set_index(Node **stack)
{
	int			i;
	struct Node	*current;

	i = 1;
	current = (*stack)->next;
	(*stack)->pos = 1;
	while (current != *stack)
	{
		i++;
		current->pos = i;
		current = current->next;
	}
}
