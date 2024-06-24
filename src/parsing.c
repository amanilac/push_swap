/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:50:06 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/24 15:14:29 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lst_size(t_node *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	ps_atoi(const char *str)
{
	long	nbr;
	int		sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	nbr = 0;
	while (*str && ft_isdigit(*str))
	{
		if (nbr > INT_MAX / 10 || (nbr == INT_MAX / 10 && *str > '7'))
			exit (error_msg("Error: please enter integer value"));
		nbr = nbr * 10 + (*str++ - '0');
	}
	return (nbr * sign);
}
