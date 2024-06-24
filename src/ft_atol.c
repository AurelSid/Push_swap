/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:22:29 by asideris          #+#    #+#             */
/*   Updated: 2024/06/24 14:04:41 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_skip(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f')
	{
		i++;
	}
	return (i);
}

long	numberet(const char *str, int i, int signe)
{
	long long	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if ((result * signe) > INT_MAX)
			return (LONG_MAX);
		else if ((result * signe) < INT_MIN)
			return (LONG_MIN);
		i++;
	}
	return ((long)result * signe);
}

long	ft_atol(const char *str)
{
	int	i;
	int	symbol;

	symbol = 1;
	i = ft_skip(str);
	if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		return (0);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		i++;
		symbol = -1;
	}
	else if (str[i] == '+' && ft_isdigit(str[i + 1]))
	{
		i++;
	}
	return (numberet(str, i, symbol));
}
