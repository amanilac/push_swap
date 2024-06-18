/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:16:20 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/17 18:10:42 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a) > (*stack_a)->next)
		swap_a(stack_a);
}

void	sort_three(t_node **stack_a)
{
	while (is_sorted(*stack_a) == 1)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			swap_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}

void	sort_four_to_five(t_node **stack_a, t_node **stack_b)
{
	int		smallest;
	int		index;

	index = 0;
	while (lst_size(*stack_a) > 3)
	{
		smallest = get_smallest(*stack_a);
		while ((*stack_a)->sequence != index)
		{
			if (smallest < lst_size(*stack_a))
				rotate_a(stack_a);
			else
				rev_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		index++;
	}
	sort_three(stack_a);
	while (lst_size(*stack_b) > 0)
		push_a(stack_a, stack_b);
}
