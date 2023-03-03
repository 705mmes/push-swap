/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:19:25 by sammeuss          #+#    #+#             */
/*   Updated: 2023/03/02 11:43:03 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_list *stack)
{
	stack->nose = NULL;
	stack->tail = NULL;
	stack->stack_size = 0;
}

void	print_stack(t_list *stack)
{
	t_stack	*ref;

	ref = stack->nose;
	if (!stack)
		exit(EXIT_FAILURE);
	while (ref)
	{
		printf("Value : %d  Previous : %p  Current : %p  Next : %p\n",
			ref->content, ref->previous, ref, ref->next);
		ref = ref->next;
	}
}

int	already_sorted(t_list	*stack)
{
	t_stack	*node;

	node = stack->nose;
	if (!node)
	{
		write(1, "err create_stack l26", 20);
		return (0);
	}
	while (node->next)
	{
		if (node->content > node->next->content)
		{
			write(1, "needs a sort\n", 13);
			return (0);
		}
		node = node->next;
	}
	write(1, "already sorted\n", 15);
	return (1);
}

int	checker(int argc, char **argv, t_list *stack)
{
	t_stack	**node;
	char	**lst;
	int		i;

	i = -1;
	(void)argc;
	node = &stack->nose;
	if (ft_check_doublons(argv) == 1)
		return (1);
	if (ft_check_args(argv[1]) == 1)
		return (1);
	if (check_int(argv) == 1)
		return (1);
	lst = ft_split(argv[1], ' ');
	i = 0;
	while (lst[i])
	{
		ft_lstadd_back(node, ft_lstnew(ft_atoi_2(lst[i])));
		i++;
	}
	print_stack(stack);
	return (0);
}

int	checker_ml(int argc, char **argv, t_list *stack)
{
	t_stack	**node;
	int		i;

	i = 1;
	node = &stack->nose;
	if (ft_check_doublons_ml(argc, argv) == 1)
		return (1);
	if (ft_check_args_ml(argv, argc) == 1)
		return (1);
	if (check_int_ml(argc, argv) == 1)
		return (1);
	while (argv[i])
	{
		ft_lstadd_back(node, ft_lstnew(ft_atoi_2(argv[i])));
		i++;
	}
	print_stack(stack);
	return (0);
}
