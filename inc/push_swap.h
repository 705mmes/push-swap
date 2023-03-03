/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:21 by smunio            #+#    #+#             */
/*   Updated: 2023/03/03 11:43:31 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 _______ _______ _______ 
|\     /|\     /|\     /|
| +---+ | +---+ | +---+ |
| |   | | |   | | |   | |
| |L  | | |I  | | |B  | |
| +---+ | +---+ | +---+ |
|/_____\|/_____\|/_____\|
                        
*/

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	t_stack	*nose;
	t_stack	*tail;
	int		stack_size;
}			t_list;
/*
*
	| PARSING |
*
*/

int			already_sorted(t_list	*stack);

int			ft_check_doublons_ml(int argc, char **argv);
int			ft_check_doublons(char **argv);

int			ft_check_args_ml(char **stack, int argc);
int			ft_check_args(char *str);

int			checker(int argc, char **argv, t_list *stack);
int			checker_ml(int argc, char **argv, t_list *stack);

long long	ft_atoi_2(char *str);
int			count_args(char **argv);

int			check_int(char **argv);
int			check_int_ml(int argc, char **argv);

void		double_free_dif(long long *tab, char **stack);
void		error(void);

/*
*
	| MANAGEMENT |
*
*/

void		init_stack(t_list	*stack);
void		print_stack(t_list *stack);

/*
*
	| ACTIONS |
*
*/

void		push_a(t_list	*stack_ref_a, t_list *stack_ref_b, int print);
void		push_b(t_list	*stack_ref_a, t_list *stack_ref_b, int print);

void		rotate(t_list *ref_stack, int choice, int print);
void		rr(t_list	*ref_stack_a, t_list	*ref_stack_b);

void		reverse_rotate_a(t_list *ref_stack, int print);
void		reverse_rotate_b(t_list *ref_stack, int print);
void		rrr(t_list	*ref_stack_b, t_list	*ref_stack_a);

void		swap(t_list *stack, int choice, int print);
void		ss(t_list	*stack_a, t_list	*stack_b);

#endif