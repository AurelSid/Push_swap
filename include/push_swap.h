/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:28:23 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 15:20:15 by asideris         ###   ########.fr       */
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
}				t_node;
long			ft_atol(const char *str);
int				ft_populate(t_node **stack_a_top, int argc, char **argv);
void			ft_add_node_to_stack(t_node **stack, int n);
void			ft_sort_stack(t_node **stack_a, t_node **stack_b);
void			ft_print_list(t_node *lst);
t_node			*ft_create_node(int value);
t_node			*ft_find_last(t_node *top);
t_node			*ft_find_smallest_cost(t_node *head);
void			ft_set_targets_b(t_node *a, t_node *b);
void			ft_set_targets_a(t_node *a, t_node *b);
void			ft_final_sort(t_node **top);
int				ft_error_syntax(char *str_n);
void			ft_set_cheapest(t_node *stack_top);
void			ft_init_nodes_a(t_node **a, t_node **b);
void			ft_init_nodes_b(t_node **a, t_node **b);
void			ft_push_a_to_b(t_node **a, t_node **b);
void			ft_push_b_to_a(t_node **a, t_node **b);
void			ft_set_to_top(t_node **top, t_node **t_node, char stack_id);

//
void			sa(t_node **top);
void			pa(t_node **a, t_node **b);
void			ra(t_node **topa);
void			rra(t_node **topa);
void			sb(t_node **top);
void			pb(t_node **a, t_node **b);
void			rb(t_node **topa);
void			rrb(t_node **topa);
void			ft_rot_both(t_node **a, t_node **b);
void			ft_rev_rot_both(t_node **a, t_node **b);
//
int				ft_listlen(t_node *lst);
void			ft_print_list(t_node *lst);
double			ft_get_median(t_node *top);
t_node			*ft_find_max(t_node *stack);
t_node			*ft_find_min(t_node *stack);
//
void			ft_sort_three(t_node **top);
void			set_index(t_node **stack);
void			ft_set_stack_costs(t_node *a, t_node *b);
//
int				ft_is_valid_int(int value);
int				ft_has_duplicates(t_node *start);
int				ft_all_checks(t_node *start);
int				ft_get_args(t_node **top, char **argv);
int				ft_sort_two(int argc, char **argv, t_node **stack);
//
bool			ft_check_sorted(t_node *stack_top);

#endif