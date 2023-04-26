/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:17:36 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/21 15:18:56 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_list	*stack_a, t_list *stack_b)
{
	int	chunk_size;
	int	i;

	i = 1;
	chunk_size = define_chunk_size(stack_a);
	while (stack_a->stack_size > chunk_size)
	{
		push_smaller_ranks(stack_a, stack_b, chunk_size, i);
		i++;
	}
	push_last_chunk(stack_a, stack_b);
	ranking(stack_b);
	empty_b(stack_a, stack_b);
	ranking(stack_a);
}

void	push_last_chunk(t_list *stack_a, t_list *stack)
{
	int	smallest;

	smallest = find_sml_rank(stack_a);
	while (stack_a->stack_size > 0)
	{
		if (stack_a->nose->rank != smallest)
			rotate(stack_a, 0, 0);
		push_b(stack_a, stack, 0);
	}
}

int	find_highest_rank(t_list *stack_ref)
{
	int			highest;
	t_stack		*stack;

	stack = stack_ref->nose;
	highest = stack->rank;
	while (stack)
	{
		if (stack->rank > highest)
			highest = stack->rank;
		stack = stack->next;
	}
	return (highest);
}

int	find_second_highest(t_list *stack_ref, int higher)
{
	int			highest;
	t_stack		*stack;

	stack = stack_ref->nose;
	highest = stack->rank;
	while (stack)
	{
		if (stack->rank == higher - 1)
			highest = stack->rank;
		stack = stack->next;
	}
	return (highest);
}

void	empty_b(t_list *stack_a, t_list *stack)
{
	int	highest;
	int	rk_i;
	int	sec_h;

	while (stack->stack_size > 0)
	{
		highest = find_highest_rank(stack);
		rk_i = find_rank_index(stack, highest);
		sec_h = find_second_highest(stack, highest);
		while (stack->nose->rank < highest)
		{
			if (stack->nose->rank == sec_h)
				push_a(stack_a, stack, 0);
			else if (rk_i < (stack->stack_size / 2))
			{
				rotate(stack, 1, 0);
			}
			else
				reverse_rotate_b(stack, 0);
		}
		push_a(stack_a, stack, 0);
		if (stack_a->nose && stack_a->nose->next
			&& stack_a->nose->rank > stack_a->nose->next->rank)
			swap(stack_a, 0, 0);
	}
}
