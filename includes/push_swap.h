/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanilac <amanilac@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:27:44 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/18 17:19:29 by amanilac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				sequence;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

char	**check_args(int argc, char **argv);
int		is_int(char *argv);
// void	print_list(t_node *stack);

void	check_dupes(t_node *stack, int num);
t_node	*getlast(t_node *lst);
t_node	*getfirst(t_node *lst);
void	init_a(t_node **stack, int data);

void	free_lst(t_node **stack);
void	free_arr(char **array);
int		error_msg(char *str);

void	swap(t_node **first);
void	rotate(t_node **first);
void	rev_rotate(t_node **first);
void	push(t_node **src, t_node **dst);

void	add_front(t_node **lst, t_node *new);

void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ab(t_node **stack_a, t_node **stack_b);

void	rotate_ab(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);

void	rev_rotate_a(t_node **stack_a);
void	rev_rotate_b(t_node **stack_b);
void	rev_rotate_ab(t_node **stack_a, t_node **stack_b);

void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);

int		is_sorted(t_node *stack_a);
int		get_smallest(t_node *stack);
void	sort_stack(t_node **stack_a);

int		lst_size(t_node *stack);
t_node	*fill_stack(char **args, t_node **stack);
int		ps_atoi(const char *str);

void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_four_to_five(t_node **stack_a, t_node **stack_b);

void	radix_sort(t_node **stack_a, t_node **stack_b);
int		biggest(t_node *stack);
void	rb_or_pa(t_node **stack_a, t_node **stack_b, int i);

int		has_sequence(t_node *stack);
void	assign_sequence(t_node *stack);
t_node	*next_small(t_node *stack);

#endif