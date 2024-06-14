/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:41:58 by asideris          #+#    #+#             */
/*   Updated: 2024/06/10 13:49:12 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_set_to_top(Node **top, Node **node, char stack_id)
{
	while (*node != *top)
	{
		if (stack_id == 'a')
		{
			if ((*node)->over_middle == 1)
				ra(&*top);
			else
				rra(&*top);
		}
		if (stack_id == 'b')
		{
			if ((*node)->over_middle == 1)
				rb(&*top);
			else
				rrb(&*top);
		}
	}
}