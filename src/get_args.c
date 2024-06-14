/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:23:54 by asideris          #+#    #+#             */
/*   Updated: 2024/06/14 12:20:50 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_args(struct Node **top, char **argv)
{
	int		i;
	char	**arg_string;
	int		j;

	i = 0;
	arg_string = ft_split(argv[1], ' ');
	while (arg_string[i])
		i++;
	j = 0;
	while (j < i)
	{
		if (arg_string == NULL)
			return (0);
		if (ft_atol(arg_string[j]) < INT_MIN
			|| ft_atol(arg_string[j]) > INT_MAX)
			return (0);
		if (ft_error_syntax(arg_string[j]))
			return (0);
		ft_add_node_to_stack(top, ft_atol(arg_string[j]));
		j++;
	}
	if (i <= 1)
	{
		exit(0);
	}
	return (1);
}
