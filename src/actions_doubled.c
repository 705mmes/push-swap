/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_doubled.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:14:01 by sammeuss          #+#    #+#             */
/*   Updated: 2023/03/03 12:28:42 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ss(t_list	*stack_a, t_list	*stack_b)
{
	swap(stack_a, 0, 705);
	swap(stack_b, 5, 705);
	write(1, "ss\n", 3);
}

void	rrr(t_list	*ref_stack_b, t_list	*ref_stack_a)
{
	reverse_rotate_a(ref_stack_a, 705);
	reverse_rotate_b(ref_stack_b, 705);
	write(1, "rrr\n", 4);
}

void	rr(t_list	*ref_stack_a, t_list	*ref_stack_b)
{
	rotate(ref_stack_a, 0, 705);
	rotate(ref_stack_b, 0, 705);
	write(1, "rr\n", 3);
}

void	reverse_rotate_b(t_list *ref_stack, int print)
{
	t_stack	*tmp;

	if (ref_stack->nose && ref_stack->nose->next)
	{
		tmp = ft_lstlast(ref_stack->nose);
		if ((tmp)->previous)
			tmp->previous->next = 0;
		ft_lstadd_front(&ref_stack->nose, tmp);
		if (print == 0)
			write(1, "rrb\n", 4);
	}
}
