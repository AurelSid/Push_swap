/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:31:34 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:37:55 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>
#include <stdio.h>

int	ft_is_valid_int(int value)
{
	return (value >= INT_MIN && value <= INT_MAX);
}

int	ft_all_valid_ints(struct Node *start)
{
	struct Node	*current;

	if (!start)
		return (0);
	current = start;
	while (current)
	{
		if (!ft_is_valid_int(current->value))
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int	ft_error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	ft_all_checks(t_node *start)
{
	if (ft_has_duplicates(start) == 1)
		return (1);
	if (ft_all_valid_ints(start) == 1)
		return (1);
	return (0);
}
