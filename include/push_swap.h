/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:23 by asideris          #+#    #+#             */
/*   Updated: 2024/06/14 14:04:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct Node
{
	int			over_middle;
	int			value;
	int			pos;
	int			cost;
	bool		cheapest;
	struct Node	*next;
	struct Node	*prev;
	struct Node	*best_friend;
}				Node;
long			ft_atol(const char *str);
int				ft_populate(struct Node **stack_a_top, int argc, char **argv);
void			ft_add_node_to_stack(Node **stack, int n);
void			ft_sort_stack(Node **stack_a, Node **stack_b);
void			ft_print_list(Node *lst);
struct Node		*ft_create_node(int value);
Node			*ft_find_last(Node *top);
Node			*ft_find_smallest_cost(Node *head);
void			ft_set_targets_b(Node *a, Node *b);
void			ft_set_targets_a(Node *a, Node *b);
void			ft_final_sort(Node **top);
int				ft_error_syntax(char *str_n);
void			ft_set_cheapest(Node *stack_top);
void			ft_init_nodes_a(Node **a, Node **b);
void			ft_init_nodes_b(Node **a, Node **b);
void			ft_push_a_to_b(Node **a, Node **b);
void			ft_push_b_to_a(Node **a, Node **b);
void			ft_set_to_top(Node **top, Node **node, char stack_id);


//
void			sa(struct Node **top);
void			pa(struct Node **a, struct Node **b);
void			ra(struct Node **topa);
void			rra(struct Node **topa);
void			sb(struct Node **top);
void			pb(struct Node **a, struct Node **b);
void			rb(struct Node **topa);
void			rrb(struct Node **topa);
void			ft_rot_both(Node **a, Node **b);
void			ft_rev_rot_both(Node **a, Node **b);
//
int				ft_listlen(struct Node *lst);
void			ft_print_list(struct Node *lst);
double			ft_get_median(struct Node *top);
Node			*ft_find_max(Node *stack);
Node			*ft_find_min(Node *stack);
//
void			ft_sort_three(Node **top);
void			set_index(Node **stack);
void			ft_set_stack_costs(Node *a, Node *b);
//
int				ft_is_valid_int(int value);
int				ft_has_duplicates(struct Node *start);
int				ft_all_checks(Node *start);
int				ft_get_args(struct Node **top, char **argv);
int				ft_sort_two(int argc, char **argv, Node **stack);
//
bool			ft_check_sorted(Node *stack_top);

#endif