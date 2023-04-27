/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:26:48 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/27 14:30:22 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	if (argc == 2)
	{
		if (checker(argc, argv, stack_a) == 1)
			error();
	}
	else if (checker_ml(argc, argv, stack_a) == 1)
		error();
	sorter(stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
