/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:14:00 by asideris          #+#    #+#             */
/*   Updated: 2024/06/14 13:14:17 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	struct Node	*stack_a_top;
	struct Node	*stack_b_top;

	stack_b_top = NULL;
	stack_a_top = NULL;
	if (argc == 1)
		return (0);
	if (argc == 3)
	{
		ft_sort_two(argc, *&argv, &stack_a_top);
		return (0);
	}
	if (ft_populate(&stack_a_top, argc, argv) != 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_sort_stack(&stack_a_top, &stack_b_top);
	ft_final_sort(&stack_a_top);
	return (0);
}
void	ft_final_sort(Node **top)
{
	Node	*min;

	min = ft_find_min(*top);
	set_index(top);
	while (*top != min)
	{
		if (min->over_middle == 1)
		{
			ra(top);
		}
		else
		{
			rra(top);
		}
	}
}
int	ft_sort_two(int argc, char **argv, Node **stack)
{
	int	value1;
	int	value2;
	int	count;

	count = argc;
	if (ft_error_syntax(argv[1]) || ft_error_syntax(argv[2]))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[2]);
	ft_add_node_to_stack(stack, value1);
	ft_add_node_to_stack(stack, value2);
	if (value1 > value2)
		ra(stack);
	return (1);
}
