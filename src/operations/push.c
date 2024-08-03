/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:20:11 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/03 18:23:04 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size)
	{
		i = a->size;
		while (i)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = b->data[0];
		a->size++;
		i = 0;
		while (i < b->size -1)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->size--;
		// write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size)
	{
		i = b->size;
		while (i)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[0] = a->data[0];
		b->size++;
		i = 0;
		while (i < a->size -1)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->size--;
		// write(1, "pb\n", 3);
	}
}
