/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:38:06 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/03 14:35:37 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *a)
{
	int	first;
	int	i;

	i = 0;
	if (a->size > 1)
	{
		first = a->data[0];
		while (i < a->size - 1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[a->size - 1] = first;
	}
}

void	rb(t_stack *b)
{
	int	first;
	int	i;

	i = 0;
	if (b->size > 1)
	{
		first = b->data[0];
		while (i < b->size - 1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[b->size - 1] = first;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
