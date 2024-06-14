/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:52:18 by asideris          #+#    #+#             */
/*   Updated: 2024/06/11 17:26:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool ft_check_sorted(Node *stack_top)
{
	Node *curr;

	curr = stack_top;
	while(curr->next)
	{
		if(curr->value > curr->next->value)
			return(false);
		curr = curr->next;
	}
	return(true);
}