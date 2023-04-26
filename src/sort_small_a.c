/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:56:12 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/21 15:14:37 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3_a(t_list *stack)
{
	t_stack		*head;
	t_stack		*next_to_head;

	head = stack->nose;
	next_to_head = stack->nose->next;
	if (head->rank == 2 && next_to_head->rank != 0)
	{
		swap(stack, 0, 0);
		reverse_rotate_a(stack, 0);
	}
	if (head->rank == 0 && next_to_head->rank == 2)
	{
		swap(stack, 0, 0);
		rotate(stack, 0, 0);
	}
	if (head->rank == 1 && next_to_head->rank == 2)
		reverse_rotate_a(stack, 0);
	if (head->rank == 1 && next_to_head->rank == 0)
		swap(stack, 0, 0);
	if (head->rank == 2 && next_to_head->rank == 0)
		rotate(stack, 0, 0);
}

void	sort_small_a(t_list	*stack_a, t_list	*stack_b)
{
	while (stack_a->stack_size > 3)
	{
		change_nose_stack_a(stack_a, 0);
		push_b(stack_a, stack_b, 0);
		ranking(stack_a);
		ranking(stack_b);
	}
	sort_3_a(stack_a);
}
