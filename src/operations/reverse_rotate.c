/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:50:00 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 15:35:25 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *a, int j)
{
	int	last;
	int	i;

	if (a->size > 1)
	{
		last = a->data[a->size - 1];
		i = a->size - 1;
		while (i)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = last;
		if (j)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b,int j)
{
	int	last;
	int	i;

	if (b->size > 1)
	{
		last = b->data[b->size - 1];
		i = b->size - 1;
		while (i)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = last;
		if (j)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
