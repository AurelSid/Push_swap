/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pupulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:57:36 by asideris          #+#    #+#             */
/*   Updated: 2024/06/14 12:00:17 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

struct Node	*ft_create_node(int value)
{
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		return (NULL);
	}
	newNode->value = value;
	newNode->over_middle = 0;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->pos = 0;
	newNode->best_friend = NULL;
	newNode->cheapest = false;
	return (newNode);
}

void	ft_add_node_to_stack(Node **stack, int n)
{
	Node	*node;
	Node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(Node));
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

int	ft_populate(struct Node **stack_a_top, int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	if (argc > 2)
	{
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
	}
	else if (!ft_get_args(stack_a_top, argv))
	{
		if(ft_get_args(stack_a_top, argv) == 2)
			write(1,"Error\n",6);
		return(0);
	}
	if (ft_all_checks(*stack_a_top) == 1 || ft_listlen(*stack_a_top) < 2)
		return (0);
	return (1);
}
