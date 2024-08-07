/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:02:59 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 15:35:50 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *a, int j)
{
	int	temp;

	temp = 0;
	if (a->size > 1)
	{
		temp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = temp;
		if (j)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b, int j)
{
	int	temp;

	temp = 0;
	if (b->size > 1)
	{
		temp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = temp;
		if (j)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
