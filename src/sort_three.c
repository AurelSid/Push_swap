/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:03:47 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:04:54 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_sort_three(t_node **top)
{
	int	first;
	int	second;
	int	third;

	first = (*top)->value;
	second = (*top)->next->value;
	third = (*top)->next->next->value;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && third > first)
		sa(top);
	if (first < second && second > third && third > first)
	{
		rra(top);
		sa(top);
	}
	if (first < second && second > third && third < first)
		rra(top);
	if (first > second && second > third)
	{
		sa(top);
		rra(top);
	}
	if (first > second && second < third && third < first)
		ra(top);
}
