/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:26:48 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/27 11:59:34 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	init_stack(&stack_b);
	init_stack(&stack_a);
	if (argc == 2)
	{
		if (checker(argc, argv, &stack_a) == 1)
			error();
	}
	else if (checker_ml(argc, argv, &stack_a) == 1)
		error();
	sorter(&stack_a, &stack_b);
	if ((&stack_a)->nose)
	{
		while ((&stack_a)->nose)
		{
			free((&stack_a)->nose);
			(&stack_a)->nose = (&stack_a)->nose->next;
		}
	}
	return (0);
}
