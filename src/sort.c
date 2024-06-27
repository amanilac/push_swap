/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:16:20 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/27 17:03:24 by amanilac         ###   ########.fr       */
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
	int	first;
	int	sec;
	int	third;

	first = (*stack_a)->sequence;
	sec = (*stack_a)->next->sequence;
	third = (*stack_a)->next->next->sequence;
	if ((is_sorted(*stack_a)) == 0)
		return ;
	if (first < sec && first < third)
	{
		rev_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (first > sec && sec < third && first < third)
		swap_a(stack_a);
	else if (first < sec && sec > first)
		rev_rotate_a(stack_a);
	else if (first > sec && sec < third && first > third)
		rotate_a(stack_a);
	else
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
}

void	sort_four_to_five(t_node **stack_a, t_node **stack_b)
{
	int		smallest_i;
	int		index;

	index = 0;
	while (lst_size(*stack_a) > 3)
	{
		smallest_i = get_smallest(*stack_a);
		while ((*stack_a)->sequence != index)
		{
			if (smallest_i + 1 < lst_size(*stack_a))
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
