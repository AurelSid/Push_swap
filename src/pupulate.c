/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pupulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:57:36 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 15:21:23 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

struct Node	*ft_create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->value = value;
	new_node->over_middle = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->pos = 0;
	new_node->best_friend = NULL;
	new_node->cheapest = false;
	return (new_node);
}

void	ft_add_node_to_stack(t_node **stack, int n)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	ft_process_args(t_node **stack_a_top, int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (ft_error_syntax(argv[i]))
			return (0);
		value = ft_atol(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		ft_add_node_to_stack(stack_a_top, value);
		i++;
	}
	return (1);
}

int	ft_populate(t_node **stack_a_top, int argc, char **argv)
{
	if (argc > 2)
	{
		if (!ft_process_args(stack_a_top, argc, argv))
			return (0);
	}
	else if (!ft_get_args(stack_a_top, argv))
	{
		if (ft_get_args(stack_a_top, argv) == 2)
			write(1, "Error\n", 6);
		return (0);
	}
	if (ft_all_checks(*stack_a_top) == 1 || ft_listlen(*stack_a_top) < 2)
		return (0);
	return (1);
}
