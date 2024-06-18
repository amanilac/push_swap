/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:33:49 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/12 01:27:35 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_node **stack_a)
{
	if (stack_a)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	rotate_b(t_node **stack_b)
{
	if (stack_b)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	if (stack_a && stack_b)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}
