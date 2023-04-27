/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:51:58 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/27 14:18:25 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*init_stack(void)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	stack->nose = NULL;
	stack->tail = NULL;
	stack->stack_size = 0;
	return (stack);
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_stack	*ref;

	ref = stack_a->nose;
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	printf("__STACK-A__\n");
	while (ref)
	{
		printf("Size : %d Value : %d Rank : %d Prev : %p Curr : %p Next : %p\n",
			stack_a->stack_size, ref->content, ref->rank, ref->previous, ref,
			ref->next);
		ref = ref->next;
	}
	ref = stack_b->nose;
	write(1, "\n", 1);
	printf("__STACK-B__\n");
	while (ref)
	{
		printf("Size : %d Value : %d Rank : %d Prev : %p Curr : %p Next : %p\n",
			stack_b->stack_size, ref->content, ref->rank, ref->previous, ref,
			ref->next);
		ref = ref->next;
	}
}

void	ranking(t_list *stack)
{
	t_stack		*first_ref;
	t_stack		*node;
	t_stack		*list;
	int			i;

	first_ref = stack->nose;
	node = first_ref;
	list = first_ref;
	i = 0;
	while (node)
	{
		while (list)
		{
			if (node->content > list->content)
				i++;
			list = list->next;
		}
		node->rank = i;
		list = first_ref;
		i = 0;
		node = node->next;
	}
}

int	find_rank_index(t_list	*stack, int rank)
{
	int		i;
	t_stack	*nose;

	nose = stack->nose;
	i = 0;
	while (nose)
	{
		if (nose->rank == rank)
			return (i);
		i++;
		nose = nose->next;
	}
	return (0);
}

void	change_nose_stack_a(t_list *stack, int new_nose_rank)
{
	int		rank_index;

	rank_index = find_rank_index(stack, new_nose_rank);
	if (rank_index >= (stack->stack_size / 2))
		while (stack->nose->rank != new_nose_rank)
			reverse_rotate_a(stack, 0);
	if (rank_index < (stack->stack_size / 2))
		while (stack->nose->rank != new_nose_rank)
			rotate(stack, 0, 0);
}
