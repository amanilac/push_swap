/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:09:22 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/08 17:08:33 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_msg(char *str)
{
	ft_printf("%s\n", str);
	return (0);
}

void	free_lst(t_node **stack)
{
	t_node	*temp;

	temp = *stack;
	if (stack)
	{
		while (temp)
		{
			temp = temp->next;
			free(*stack);
			*stack = temp;
		}
	}
}

void	free_arr(char **array)
{
	size_t	i;

	i = 0;
	if (array)
	{
		while (array[i])
			free(array[i++]);
	}
	free(array);
}
