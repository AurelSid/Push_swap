/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:06 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:38:06 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_set_stack_costs(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_listlen(a);
	len_b = ft_listlen(b);
	while (a)
	{
		a->cost = a->pos;
		if (a->pos > len_a / 2)
			a->cost = len_a - (a->pos);
		if (a->best_friend->pos < len_b / 2)
			a->cost += a->best_friend->pos;
		else
			a->cost += len_b - (a->best_friend->pos);
		a = a->next;
	}
}
