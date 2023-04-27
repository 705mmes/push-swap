/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:37:16 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/27 15:04:40 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	check_output(char *action, t_list stack_a, t_list stack_b)
{
	if (!ft_strncmp(action, "sa\n", ft_strlen(action)))
		swap(&stack_a, 0, 1);
	else if (!ft_strncmp(action, "sb\n", ft_strlen(action)))
		swap(&stack_b, 1, 1);
	else if (!ft_strncmp(action, "ss\n", ft_strlen(action)))
		ss(&stack_a, &stack_b, 1);
	else if (!ft_strncmp(action, "pa\n", ft_strlen(action)))
		push_a(&stack_a, &stack_b, 1);
	else if (!ft_strncmp(action, "pb\n", ft_strlen(action)))
		push_b(&stack_a, &stack_b, 1);
	else if (!ft_strncmp(action, "ra\n", ft_strlen(action)))
		rotate(&stack_a, 0, 1);
	else if (!ft_strncmp(action, "rb\n", ft_strlen(action)))
		rotate(&stack_b, 1, 1);
	else if (!ft_strncmp(action, "rr\n", ft_strlen(action)))
		rr(&stack_a, &stack_b, 1);
	else if (!ft_strncmp(action, "rra\n", ft_strlen(action)))
		reverse_rotate_a(&stack_a, 1);
	else if (!ft_strncmp(action, "rrb\n", ft_strlen(action)))
		reverse_rotate_b(&stack_b, 1);
	else if (!ft_strncmp(action, "rrr\n", ft_strlen(action)))
		rrr(&stack_b, &stack_a, 1);
	else
		(write(2, "Error\n", 6), exit(1));
}

void	init_check(int argc, char **argv, t_list stack_a)
{
	if (argc == 2)
	{
		if (checker(argc, argv, &stack_a) == 1)
			error();
	}
	else if (checker_ml(argc, argv, &stack_a) == 1)
		error();
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*action;

	stack_a = init_stack();
	stack_b = init_stack();
	if (argc == 2)
		if (checker(argc, argv, stack_a) == 1)
			error();
	if (argc > 2 && checker_ml(argc, argv, stack_a) == 1)
		error();
	action = get_next_line(0);
	while (action)
	{
		check_output(action, *stack_a, *stack_b);
		if (already_sorted(stack_a) && stack_b->stack_size == 0)
			break ;
		action = get_next_line(0);
	}
	if (already_sorted(stack_a) && stack_b->stack_size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
