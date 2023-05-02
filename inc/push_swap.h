/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:31:21 by smunio            #+#    #+#             */
/*   Updated: 2023/05/02 14:45:47 by smunio           ###   ########.fr       */
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
// # include "src/checker/get_next_line/get_next_line_L.h"

typedef struct s_list
{
	t_stack	*nose;
	t_stack	*tail;
	int		stack_size;
}			t_list;

//	->checker

void		check_output(char *line, t_list stack_a, t_list stack_b);
void		init_check(int argc, char **argv, t_list stack_a);
void		free_stacks(t_list *stack_a, t_list *stack_b);

//-------------
/*
*
	| PARSING |
*
*/

// -> parsing.c

void		error(void);
int			ft_check_args(char *str);
int			ft_check_doublons(char **argv);
int			ft_check_args_ml(char **stack, int argc);
int			ft_check_doublons_ml(int argc, char **argv);

// -> parsing_2.c

long long	ft_atoi_2(char *str);
int			check_int(char **argv);
int			check_int_ml(int argc, char **argv);
int			count_args(char **argv);
void		double_free_dif(long long *tab, char **stack);

// -> parsing\init.c

char		*free_split(char **s);
int			already_sorted(t_list	*stack);
int			checker(int argc, char **argv, t_list *stack);
int			checker_ml(int argc, char **argv, t_list *stack);

/*
*
	| MANAGEMENT |
*
*/

// -> utils.c
t_list		*init_stack(void);
void		print_stacks(t_list *stack_a, t_list *stack_b);
void		ranking(t_list *stack);
int			find_rank_index(t_list	*stack, int rank);
void		change_nose_stack_a(t_list *stack, int new_nose_rank);

// -> utils2.c

void		push_smaller_ranks(t_list *stack_a, t_list *stack, int ck_s, int i);
int			define_chunk_size(t_list *stack);
void		sorter(t_list *stack_a, t_list *stack_b);
int			find_sml_rank(t_list *stack_ref);

/*
*
	| ACTIONS |
*
*/

// -> actions.c

void		push_a(t_list	*stack_ref_a, t_list *stack_ref_b, int print);
void		push_b(t_list	*stack_ref_a, t_list *stack_ref_b, int print);
void		swap(t_list *stack, int choice, int print);
void		rotate(t_list *ref_stack, int choice, int print);
void		reverse_rotate_a(t_list *ref_stack, int print);
void		reverse_rotate_b(t_list *ref_stack, int print);

// -> actions_doubled.c

void		rr(t_list	*ref_stack_a, t_list	*ref_stack_b, int choice);
void		rrr(t_list	*ref_stack_b, t_list	*ref_stack_a, int choice);
void		ss(t_list	*stack_a, t_list	*stack_b, int choice);

/*
*
	| SORTING |
*
*/

void		sort_3_a(t_list *stack);
void		sort_small_a(t_list *stack_a, t_list	*stack_b);

// -> sort_big.c

void		sort_big(t_list	*stack_a, t_list *stack_b);
void		push_last_chunk(t_list *stack_a, t_list *stack);
int			find_highest_rank(t_list *stack_ref);
int			find_second_highest(t_list *stack_ref, int higher);
void		empty_b(t_list *stack_a, t_list *stack_b);

/*
*
	| GNL LEON |
*
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*all_before_backslash_n(char *str);
char		*all_after_backslash_n(char *str);
char		*ft_strjoin(char *str, char *buffer, int len);
char		*freeall(char **str);
char		*freeallspe(char **str);
char		*doublefree(char *str, char **result);
int			ft_strlen_gnl(char *str);
int			check_backslash(char *save, int u);

#endif