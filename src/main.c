/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:26:48 by sammeuss          #+#    #+#             */
/*   Updated: 2023/03/03 12:14:40 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_1;
	t_list	stack_2;

	init_stack(&stack_2);
	init_stack(&stack_1);
	if (argc == 2)
	{
		if (checker(argc, argv, &stack_1) == 1)
			error();
	}
	else if (checker_ml(argc, argv, &stack_1) == 1)
		error();
	if (already_sorted(&stack_1) == 1)
		exit(EXIT_SUCCESS);
	// push(&stack_1, &stack_2, 0);
	// push(&stack_1, &stack_2, 0);
	// swap(&stack_1, 0);
	reverse_rotate_a(&stack_1, 0);
	print_stack(&stack_1);
	write(1, "\n", 1);
	// print_stack(&stack_2);
	return (0);
}
