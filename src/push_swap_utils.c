/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:14 by asideris          #+#    #+#             */
/*   Updated: 2024/06/13 14:05:28 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	ft_listlen(struct Node *lst)
{
	int			i;
	struct Node	*current;

	current = lst;
	i = 0;
	while (current)
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
		ft_printf("List is empty\n");
		return ;
	}
	tmp = lst;
	while (tmp)
	{
		ft_printf("node: %-8d   pos: %-1d cost: %-1d over middle: %-1d\n",
				tmp->value,
				tmp->pos,
				tmp->cost,
				tmp->over_middle);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
