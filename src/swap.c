/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:26:30 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/10 19:26:54 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_node **stack_a)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}

void	swap_b(t_node **stack_b)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->next && (*stack_b) && (*stack_b)->next)
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
}
