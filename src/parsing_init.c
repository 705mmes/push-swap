/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:45:03 by sammeuss          #+#    #+#             */
/*   Updated: 2023/04/26 13:55:02 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*free_item(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
		return (*s);
	}
	return (NULL);
}

int	already_sorted(t_list	*stack)
{
	t_stack	*node;

	node = stack->nose;
	if (!node)
		return (0);
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
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
		stack->stack_size++;
		i++;
	}
	ranking(stack);
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
		stack->stack_size++;
		i++;
	}
	ranking(stack);
	return (0);
}
