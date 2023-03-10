/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:57:48 by sammeuss          #+#    #+#             */
/*   Updated: 2023/03/03 12:25:53 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list *stack_ref, int choice, int print)
{
	t_stack	*tmp;

	if (stack_ref->nose && stack_ref->nose->next)
	{
		tmp = stack_ref->nose;
		stack_ref->nose = stack_ref->nose->next;
		stack_ref->nose->previous = 0;
		tmp->next = stack_ref->nose->next;
		tmp->previous = stack_ref->nose;
		stack_ref->nose->next = tmp;
		if (stack_ref->nose->next->next)
			stack_ref->nose->next->next->previous = tmp;
		if (print == 0)
		{
			if (choice == 0)
				write(1, "sa\n", 3);
			else
				write(1, "sb\n", 3);
		}
	}
}

void	push_a(t_list	*stack_ref_a, t_list *stack_ref_b, int print)
{
	t_stack	*tmp;

	if (stack_ref_a->nose)
	{
		tmp = stack_ref_a->nose;
		stack_ref_a->nose = stack_ref_a->nose->next;
		stack_ref_a->nose->previous = 0;
		tmp->next = stack_ref_b->nose;
		tmp->previous = 0;
		if (tmp->next)
			tmp->next->previous = tmp;
		stack_ref_b->nose = tmp;
		if (print == 0)
			write(1, "pa\n", 3);
	}
}

void	push_b(t_list	*stack_ref_a, t_list *stack_ref_b, int print)
{
	t_stack	*tmp;

	if (stack_ref_b->nose)
	{
		tmp = stack_ref_b->nose;
		stack_ref_b->nose = stack_ref_b->nose->next;
		stack_ref_b->nose->previous = 0;
		tmp->next = stack_ref_a->nose;
		tmp->previous = 0;
		if (tmp->next)
			tmp->next->previous = tmp;
		stack_ref_a->nose = tmp;
		if (print == 0)
			write(1, "pb\n", 3);
	}
}

void	rotate(t_list *ref_stack, int choice, int print)
{
	t_stack	*tmp;

	if (ref_stack->nose && ref_stack->nose->next)
	{
		tmp = ref_stack->nose;
		ref_stack->nose = ref_stack->nose->next;
		tmp->next = 0;
		tmp->previous = ft_lstlast(ref_stack->nose);
		ft_lstlast(ref_stack->nose)->next = tmp;
		if (print == 0)
		{
			if (choice != 0)
				write(1, "rb\n", 3);
			else
				write(1, "ra\n", 3);
		}
	}
}

void	reverse_rotate_a(t_list *ref_stack, int print)
{
	t_stack	*tmp;

	if (ref_stack->nose && ref_stack->nose->next)
	{
		tmp = ft_lstlast(ref_stack->nose);
		if ((tmp)->previous)
			tmp->previous->next = 0;
		ft_lstadd_front(&ref_stack->nose, tmp);
		if (print == 0)
			write(1, "rra\n", 4);
	}
}
