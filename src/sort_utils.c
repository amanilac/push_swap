/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:47:43 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/13 14:13:02 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (1);
		else
			stack_a = stack_a->next;
	}
	return (0);
}

int	get_smallest(t_node *stack)
{
	t_node	*temp;
	int		i;
	int		smallest;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
	smallest = stack->index;
	while (stack)
	{
		if (stack->index > smallest)
			smallest = stack->index;
		stack = stack->next;
	}
	return (smallest);
}

void	sort_stack(t_node **stack_a)
{
	t_node	*stack_b;
	int		size;

	stack_b = NULL;
	if (!stack_a)
		error_msg("Error");
	size = lst_size(*stack_a);
	assign_sequence(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_four_to_five(stack_a, &stack_b);
	else
		radix_sort(stack_a, &stack_b);
}
