/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:48:07 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/11 17:35:50 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_sequence(t_node *stack)
{
	while (stack)
	{
		if (stack->sequence < 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_node	*next_small(t_node *stack)
{
	t_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (smallest->sequence >= 0)
			smallest = smallest->next;
		if (smallest->data > stack->data && stack->sequence < 0)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	assign_sequence(t_node *stack)
{
	int		i;
	t_node	*smallest;

	i = 0;
	while (has_sequence(stack) == 1)
	{
		smallest = next_small(stack);
		smallest->sequence = i;
		i++;
	}
}
