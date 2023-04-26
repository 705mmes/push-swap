/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:53:30 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/22 17:58:48 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sorter(t_list *stack_a, t_list *stack_b)
{
	if (already_sorted(stack_a))
		exit(EXIT_SUCCESS);
	if (stack_a->stack_size <= 99)
	{
		sort_small_a(stack_a, stack_b);
		while (stack_b->stack_size > 0)
			push_a(stack_a, stack_b, 0);
		ranking(stack_a);
	}
	else if (stack_a->stack_size >= 100)
		sort_big(stack_a, stack_b);
}

void	push_smaller_ranks(t_list *stack_a, t_list *stack, int ck_s, int i)
{
	int	smallest;

	smallest = ck_s * i - ck_s;
	while (stack->stack_size < ck_s * i)
	{
		if (stack_a->nose->rank >= smallest
			&& stack_a->nose->rank < ((ck_s * i) - ck_s / 2))
			push_b(stack_a, stack, 0);
		else if (stack_a->nose->rank >= ((ck_s * i) - ck_s / 2)
			&& stack_a->nose->rank < ck_s * i)
		{
			push_b(stack_a, stack, 0);
			rotate(stack, 1, 0);
		}
		else
			rotate(stack_a, 0, 0);
	}
}

int	define_chunk_size(t_list *stack)
{
	int	div;

	div = 0;
	if (stack->stack_size <= 100)
		div = 6;
	else if (stack->stack_size > 100 && stack->stack_size <= 500)
		div = 8;
	else if (stack->stack_size > 500)
		div = 12;
	return (stack->stack_size / div);
}

int	find_sml_rank(t_list *stack_ref)
{
	int		smallest;
	t_stack	*head;

	head = stack_ref->nose;
	smallest = stack_ref->nose->rank;
	while (head)
	{
		if (smallest > head->rank)
			smallest = head->rank;
		head = head->next;
	}
	return (smallest);
}
