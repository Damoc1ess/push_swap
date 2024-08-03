/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:02:59 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/03 18:23:09 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	temp = 0;
	if (a->size > 1)
	{
		temp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = temp;
		// write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	int	temp;

	temp = 0;
	if (b->size > 1)
	{
		temp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = temp;
		// write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	// write(1, "ss\n", 3);
}
