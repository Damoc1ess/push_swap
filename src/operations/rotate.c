/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:50:00 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/05 13:21:43 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *a)
{
	int	first;
	int	i;

	if (a->size > 1)
	{
		first = a->data[0];
		i = 0;
		while (i < a->size)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[a->size - 1] = first;
		write(1, "ra\n", 4);
	}
}

void	rb(t_stack *b)
{
	int	first;
	int	i;

	if (b->size > 1)
	{
		first = b->data[0];
		i = 0;
		while (i < b->size -1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[b->size -1] = first;
		write(1, "rb\n", 4);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 4);
}
