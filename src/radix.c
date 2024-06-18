/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:01:33 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/18 16:42:27 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	biggest(t_node *stack)
{
	int	biggest;
	int	max_bits;

	max_bits = 0;
	biggest = stack->sequence;
	while (stack)
	{
		if (stack->sequence > biggest)
			biggest = stack->sequence;
		stack = stack->next;
	}
	while ((biggest >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	i;
	int	max;

	max = biggest(*stack_a);
	i = 0;
	while (i < max && is_sorted(*stack_a) == 1)
	{
		size = lst_size(*stack_a);
		while (size-- && (*stack_a) && is_sorted(*stack_a) == 1)
		{
			if (!(((*stack_a)->sequence >> i) & 1))
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		i++;
		while (*stack_b)
			push_a(stack_a, stack_b);
	}
}
