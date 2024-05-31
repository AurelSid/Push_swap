/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:14:00 by asideris          #+#    #+#             */
/*   Updated: 2024/05/31 14:11:59 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

struct Node	*ft_create_node(int value)
{
	struct Node	*newNode;

	newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}
	newNode->value = value;
	newNode->over_middle = 0;
	newNode->next = newNode;
	newNode->prev = newNode;
	newNode->pos = 0;
	newNode->best_friend = newNode;
	return (newNode);
}

void	ft_push_node(struct Node **top, int value)
{
	struct Node	*newNode;
	struct Node	*last;

	newNode = ft_create_node(value);
	if (*top == NULL)
	{
		*top = newNode;
	}
	else
	{
		last = (*top)->prev;
		newNode->next = *top;
		newNode->prev = last;
		last->next = newNode;
		(*top)->prev = newNode;
	}
	*top = newNode;
	// printf("%-8d pushed to the stack and set as top.\n\n", value);
}

void	**ft_get_args(struct Node **top, char **argv)
{
	int		i;
	char	**arg_string;
	int		j;

	i = 0;
	arg_string = ft_split(argv[1], ' ');
	while (arg_string[i])
		i++;
	j = i - 1;
	while (j >= 0)
	{
		ft_push_node(&*top, ft_atoi(arg_string[j]));
		j--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct Node	*stack_a_top;
	int			i;
	int			j;
	int			val_count;
	struct Node	*stack_b_top;

	stack_b_top = NULL;
	stack_a_top = NULL;
	i = argc - 1;
	val_count = argc - 1;
	if (argc == 1)
		return (0);
	ft_populate(&stack_a_top, argc, argv);
	printf("-----------------------\n");
	printf("Stack A\n");
	ft_print_list(stack_a_top);
	printf("Stack B\n");
	ft_print_list(stack_b_top);
	ft_sort_five(&stack_a_top, &stack_b_top);
	printf("-----------------------\n");
	printf("\n\n");
	j = ft_listlen(stack_b_top);
	ft_sort(&stack_a_top, &stack_b_top, j);
	stack_b_top = NULL;
	set_index(&stack_a_top);
	ft_set_stack_costs(&stack_a_top);
	ft_find_smallest_value(&stack_a_top);
	printf("Stack A\n");
	ft_print_list(stack_a_top);
	printf("Stack B\n");
	ft_print_list(stack_b_top);
	return (0);
}
void	ft_populate(Node **stack_a_top, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	if (argc > 2)
	{
		while (i > 0)
		{
			ft_push_node(*&stack_a_top, ft_atoi(argv[i]));
			i--;
		}
	}
	else
	{
		ft_get_args(*&stack_a_top, argv);
	}
}
void ft_sort(Node **stack_a_top, Node **stack_b_top, int len)
{
		while (len > 0)
	{
		ft_find_all_friends(*&stack_a_top, *&stack_b_top);
		set_index(*&stack_a_top);
		set_index(*&stack_b_top);
		ft_set_stack_costs(*&stack_a_top);
		ft_set_stack_costs(*&stack_b_top);
		ft_push_cheapest(*&stack_a_top, *&stack_b_top);
		len--;
	}
}