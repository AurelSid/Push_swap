/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:14 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:04:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	ft_listlen(t_node *lst)
{
	int		i;
	t_node	*current;

	current = lst;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_print_list(t_node *lst)
{
	t_node	*tmp;

	if (lst == NULL)
	{
		ft_printf("List is empty\n");
		return ;
	}
	tmp = lst;
	while (tmp)
	{
		ft_printf("node: %-8d   pos: %-1d cost: %-1d over middle: %-1d\n",
			tmp->value, tmp->pos, tmp->cost, tmp->over_middle);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
