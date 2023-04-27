/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:26:48 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/27 15:06:45 by smunio           ###   ########.fr       */
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
	free(stack_a);
	free(stack_b);
	return (0);
}
