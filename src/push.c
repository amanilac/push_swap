/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:31:26 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/11 17:40:51 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	if (stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	if (stack_a)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}
