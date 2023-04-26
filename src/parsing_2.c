/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:12:35 by smunio            #+#    #+#             */
/*   Updated: 2023/04/21 15:18:08 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	ft_atoi_2(char *str)
{
	long long	r;
	long long	sign;
	int			i;

	r = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (sign * r);
}

int	check_int(char **argv)
{
	char		**stack;
	long long	*tab;
	int			i;
	int			args;

	i = -1;
	stack = ft_split(argv[1], ' ');
	args = count_args(stack);
	tab = malloc(sizeof(int) * args);
	if (!tab)
		return (1);
	while (++i < args)
		tab[i] = ft_atoi_2(stack[i]);
	i = -1;
	while (++i < args)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			double_free_dif(tab, stack);
			return (1);
		}
	}
	double_free_dif(tab, stack);
	return (0);
}

int	check_int_ml(int argc, char **argv)
{
	int			i;
	long long	*tab;

	i = -1;
	tab = malloc(sizeof(int) * (count_args(argv) - 1));
	if (!tab)
		return (1);
	while (++i < (argc - 1))
		tab[i] = ft_atoi_2(argv[i + 1]);
	i = -1;
	while (++i < (argc -1))
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			free(tab);
			return (1);
		}
	}
	if (tab)
		free(tab);
	return (0);
}

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	double_free_dif(long long *tab, char **stack)
{
	free(tab);
	free(stack);
}
