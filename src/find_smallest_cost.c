/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:45:13 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:47:17 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_find_smallest_cost(t_node *head)
{
	t_node	*curr;

	curr = head;
	if (!curr)
		return (NULL);
	while (curr)
	{
		if (curr->cheapest)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
