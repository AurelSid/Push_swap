/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:39:11 by asideris          #+#    #+#             */
/*   Updated: 2024/06/10 17:30:24 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

Node	*ft_find_last(Node *top)
{
	if (!top)
		return (NULL);
	while (top->next)
		top = top->next;
	return (top);
}