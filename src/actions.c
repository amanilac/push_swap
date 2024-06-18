/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:14:19 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/17 17:57:55 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_node **first)
{
	t_node	*temp;

	temp = (*first)->next;
	(*first)->next = temp->next;
	if ((*first)->next)
		(*first)->next->prev = *first;
	temp->prev = (*first)->prev;
	(*first)->prev = temp;
	temp->next = *first;
	*first = temp;
}

void	rotate(t_node **first)
{
	t_node	*temp;
	t_node	*last;

	last = getlast(*first);
	last->next = *first;
	(*first)->prev = last;
	temp = (*first)->next;
	temp->next = (*first)->next->next;
	(*first)->next = NULL;
	*first = temp;
	(*first)->prev = NULL;
}

void	rev_rotate(t_node **first)
{
	t_node	*temp;
	t_node	*last;

	last = getlast(*first);
	temp = last->prev;
	temp->next = NULL;
	last->next = *first;
	(*first)->prev = last;
	last->prev = NULL;
	*first = last;
}

void	push(t_node **src, t_node **dst)
{
	t_node	*temp;

	temp = NULL;
	if ((*src) && (*src)->next)
		temp = (*src)->next;
	if (temp)
		temp->prev = NULL;
	if (*src)
		add_front(dst, *src);
	*src = temp;
}

void	add_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	else
		new->next = NULL;
	new->prev = NULL;
	*lst = new;
}
