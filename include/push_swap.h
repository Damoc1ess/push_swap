/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:03:07 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 12:58:44 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}				t_stack;

int				is_sorted(t_stack *a);
void			read_input(t_stack *a, int argc, char **argv);
void			init_stack(t_stack *b, int size);
int				is_sorted(t_stack *a);
void			sort_three_elements(t_stack *a, t_stack *b);
void			free_stack(t_stack *a);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
char			**ft_split(char const *s, char c);
void			ft_print_stack(t_stack *a);
int				count_words(char *s, char c);
void swap(t_stack *a, int i, int j);

#endif
