/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:20:53 by eablak            #+#    #+#             */
/*   Updated: 2023/10/20 11:58:14 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_struct	*next;
}					t_struct;

void				array_control(char *all_array);
void				check_same(int *arr, int size);
void				check_nan(char *all_arguments);
void				check_sorted(int *arr, int size);
void				start_processes(int *arr, int size);
void				process_by_size(int size, t_struct **struct_a);
void				indexing(int *arr, int size, t_struct **struct_a);
void				ra(t_struct **stack_a);
void				sa(t_struct **stack_a);
t_struct			*get_last(t_struct *stack_a);
void				rra(t_struct **stack_a);
void				big_sort(t_struct **struct_a, int size);
void				pb(t_struct **stack_a, t_struct **stack_b);
t_struct			*get_last_before(t_struct *stack);
int					get_size_struct(t_struct **strc);
void				little_sort(t_struct **stack_a);
void				current_positions(t_struct **strc);
void				target_positions(t_struct **struct_a, t_struct **struct_b);
void				calculate_const(t_struct **struct_a, t_struct **struct_b);
int					is_sorted(t_struct *strc);
void				placement(t_struct **strct_a, t_struct **strct_b);
void				rr(t_struct **stack_a, t_struct **stack_b);
void				rrr(t_struct **stack_a, t_struct **stack_b);
void				pa(t_struct **stack_a, t_struct **stack_b);
void				rrb(t_struct **stack_b);
void				rb(t_struct **stack_b);
void				ascending(t_struct **strct_a, int size);
void				position_processes(t_struct **struct_a,
						t_struct **struct_b);
void				get_const(t_struct **stack_a, t_struct **stack_b);
void				free_struct(t_struct **strc, int size);
int					get_size(char **av);
char				*unify(char **av);
int					*convert_digit(char *str, int size);
void				_rrr(t_struct **strct_a, t_struct **strct_b, int *cost_a,
						int *cost_b);
void				_rr(t_struct **strct_a, t_struct **strct_b, int *cost_a,
						int *cost_b);
void				_ra(t_struct **strct_a, t_struct **strct_b, int *cost);
void				_rb(t_struct **strct_a, t_struct **strct_b, int *cost);
#endif