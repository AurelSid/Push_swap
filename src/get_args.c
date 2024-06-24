/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:23:54 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:52:30 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_process_arg(t_node **top, char *arg)
{
	long	value;

	if (ft_error_syntax(arg))
		return (0);
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	ft_add_node_to_stack(top, value);
	return (1);
}

int	ft_get_args(t_node **top, char **argv)
{
	int		i;
	char	**arg_string;

	arg_string = ft_split(argv[1], ' ');
	if (!arg_string)
		return (0);
	i = 0;
	while (arg_string[i])
	{
		if (!ft_process_arg(top, arg_string[i]))
		{
			free(arg_string);
			return (0);
		}
		i++;
	}
	free(arg_string);
	if (i <= 1)
		exit(0);
	return (1);
}
