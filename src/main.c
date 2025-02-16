/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annamanilaci <annamanilaci@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:24:29 by amanilac          #+#    #+#             */
/*   Updated: 2024/06/24 13:42:06 by annamanilac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_int(char *argv)
{
	if (*argv == '-')
		argv++;
	while (*argv)
	{
		if (*argv >= '0' && *argv <= '9')
			argv++;
		else
			return (1);
	}
	return (0);
}

char	**check_args(int argc, char **argv)
{
	char	**split;

	split = NULL;
	if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		split = argv;
	}
	if (argv == NULL)
		exit(error_msg("Error: Malloc failure\n"));
	while (*argv)
	{
		if (is_int(*argv) == 1)
		{
			if (split)
				free_arr(split);
			exit(error_msg("Error: Incorrect input\n"));
		}
		else
			argv++;
	}
	if (split)
		return (split);
	return (argv - argc + 1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	char	**args;

	if (argc < 2)
		exit(error_msg("Error: Not enough arguments\n"));
	args = NULL;
	stack_a = NULL;
	argv++;
	args = check_args(argc, argv);
	if (!args)
	{
		free_arr(args);
		exit(error_msg("Error: Malloc failure\n"));
	}
	while (*args)
	{
		init_a(&stack_a, ps_atoi(*args));
		args++;
	}
	sort_stack(&stack_a);
	free_lst(&stack_a);
	return (0);
}
