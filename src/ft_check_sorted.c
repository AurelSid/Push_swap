/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:52:18 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:46:16 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_check_sorted(t_node *stack_top)
{
	t_node	*curr;

	curr = stack_top;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}
