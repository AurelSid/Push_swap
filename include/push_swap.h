/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:23 by asideris          #+#    #+#             */
/*   Updated: 2024/05/31 14:10:22 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdlib.h>

typedef struct Node
{
	int			over_middle;
	int			value;
	int			pos;
	int			cost;
	struct Node	*next;
	struct Node	*prev;
	struct Node	*best_friend;
}				Node;
void			ft_populate(Node **stack_a_top, int argc, char **argv);
void			ft_sort(Node **stack_a_top, Node **stack_b_top, int len);
void			sa(struct Node **top);
void			ft_push_node(struct Node **top, int value);
void			ft_print_list(Node *lst);
void			**ft_get_args(struct Node **top, char **argv);
struct Node		*ft_create_node(int value);
void			pb(struct Node **topa, struct Node **topb);
void			ra(struct Node **topa);
void			rra(struct Node **topa);
int				ft_listlen(struct Node *lst);
// int				countSmaller(Node *head, Node *current, int value);
// void			updatePositions(Node *head, Node *current);
void			ft_print_list(struct Node *lst);
int				ft_get_median(struct Node *top);
void			ft_push_median(Node **top_a, Node **top_b);

void			ft_sort_five(Node **top_a, Node **top_b);
Node			*ft_find_smallest(Node *top_a);
void			ft_sort_three(Node **top);
void			ft_find_best_friend(Node **top_a, Node **node_b);
void			set_index(Node **stack);
int				ft_find_stack_center(Node *stack);
void			ft_find_all_friends(Node **stack_a, Node **stack_b);
void			ft_set_stack_costs(Node **stack);
Node			*ft_find_smallest_cost(Node *stack_b_top);
void			ft_push_cheapest(Node **stack_a_top, Node **stack_b_top);
void			ft_set_to_top(Node **top, Node **node);
void			ft_find_smallest_value(Node **stack_a_top);

#endif