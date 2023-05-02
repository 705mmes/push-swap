/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:45:36 by smunio            #+#    #+#             */
/*   Updated: 2023/05/02 13:02:12 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_args_ml(char **stack, int argc)
{
	int	i;
	int	u;

	u = 0;
	i = 1;
	while (i < argc)
	{
		while (stack[i][u])
		{
			if ((stack[i][u] >= '0' && stack[i][u] <= '9')
				|| (stack[i][u] == '-' && u == 0))
				u++;
			else
				return (1);
		}
		u = 0;
		i++;
	}
	return (0);
}

int	ft_check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == '-' || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_doublons_ml(int argc, char **argv)
{
	int	i;
	int	u;
	int	arg;

	arg = 0;
	i = 0;
	u = 0;
	while (++i < argc)
	{
		arg = ft_atoi(argv[i]);
		while (++u < argc)
			if (i != u && arg == ft_atoi(argv[u]))
				return (1);
		u = -1;
	}
	return (0);
}

int	ft_check_doublons(char **argv)
{
	int		i;
	int		u;
	char	**tab;

	i = 0;
	u = 1;
	tab = ft_split(argv[1], ' ');
	while (tab[i])
	{
		while (tab[u])
		{
			if (i != u && ft_atoi(tab[i]) == ft_atoi(tab[u]))
			{
				free_split(tab);
				return (1);
			}
			u++;
		}
		u = 0;
		i++;
	}
	free_split(tab);
	return (0);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit (EXIT_FAILURE);
}
