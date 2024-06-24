/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:34:11 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:47:35 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicates(int *numbers, int count, int value)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (numbers[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	ft_has_duplicates(t_node *start)
{
	int		*numbers;
	int		count;
	t_node	*current;
	int		len;

	if (!start)
		return (0);
	len = ft_listlen(start);
	numbers = (int *)malloc(len * sizeof(int));
	if (!numbers)
		return (0);
	count = 0;
	current = start;
	while (current != NULL)
	{
		if (check_duplicates(numbers, count, current->value))
		{
			free(numbers);
			return (1);
		}
		numbers[count++] = current->value;
		current = current->next;
	}
	free(numbers);
	return (0);
}
