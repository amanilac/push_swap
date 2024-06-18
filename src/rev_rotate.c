/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:35:21 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/08 17:54:21 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate_a(t_node **stack_a)
{
	if (stack_a)
	{
		rev_rotate(stack_a);
		ft_printf("rra\n");
	}
}

void	rev_rotate_b(t_node **stack_b)
{
	if (stack_b)
	{
		rev_rotate(stack_b);
		ft_printf("rrb\n");
	}
}

void	rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		ft_printf("rrr\n");
	}
}
