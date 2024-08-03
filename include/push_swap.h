/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:22:02 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/03 18:31:59 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}					t_stack;

typedef struct s_solution
{
	int	*operations;
	int	op_count;
}					t_solution;

// Nombre d'opérations disponibles
#define NUM_OPERATIONS 11

// Codes des opérations
enum Operations
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};


void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	backtrack(t_stack *a, t_stack *b, t_solution *best_solution, t_solution *current_solution);

void	print_stack(t_stack *stack, const char *name);
void	read_input(t_stack *a, int argc, char **argv);
int		evaluate_solution(t_stack *a);

void	init_stack(t_stack *stack, int size);
void	free_stack(t_stack *stack);
void	copy_stack(t_stack *dest, t_stack *src);
void	undo_operation(t_stack *a, t_stack *b, int op);

int 	is_sorted(t_stack *a);
void	ft_putstr_red(char *str);

#endif
