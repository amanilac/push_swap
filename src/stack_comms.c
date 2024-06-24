/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_comms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:34:28 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/17 18:07:42 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*getfirst(t_node *lst)
{
	while (lst->prev)
		lst = lst->prev;
	lst->prev = NULL;
	return (lst);
}

t_node	*getlast(t_node *lst)
{
	while (lst->next)
		lst = lst->next;
	lst->next = NULL;
	return (lst);
}

void	check_dupes(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->data == num)
			exit (error_msg("Error: Duplicate values in argument\n"));
		stack = stack->next;
	}
}

void	init_a(t_node **stack, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		free_lst(stack);
		exit (error_msg("Error: Malloc failure\n"));
	}
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		check_dupes(*stack, num);
		new->prev = getlast(*stack);
		getlast(*stack)->next = new;
		getfirst(*stack)->prev = NULL;
	}
	new->sequence = -1;
	new->data = num;
	new->next = NULL;
}
