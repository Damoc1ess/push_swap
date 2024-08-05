#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int *data;
	int size;
} t_stack;

int		is_sorted(t_stack *a);
void	read_input(t_stack *a, int argc, char **argv);
void	init_stack(t_stack *b, int size);
int		is_sorted(t_stack *a);
void	sort_three_elements(t_stack *a, t_stack *b);
void	free_stack(t_stack *a);
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
char	**ft_split(char *str);
void	ft_print_stack(t_stack *a);

#endif
