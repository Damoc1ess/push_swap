/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:53:19 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 17:16:37 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three_elements(t_stack *a, t_stack *b)
{
	if (a->data[0] > a->data[1] && a->data[0] < a->data[2])
		sa(a, 1); // Cas: 2 1 3 -> 1 2 3
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		sa(a, 1);
		rra(a, 1); // Cas: 3 2 1 -> 2 3 1 -> 1 2 3
	}
	else if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
		ra(a, 1); // Cas: 3 1 2 -> 1 2 3
	else if (a->data[0] < a->data[1] && a->data[0] > a->data[2])
		rra(a, 1); // Cas: 2 3 1 -> 1 2 3
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2])
	{
		sa(a, 1);
		ra(a, 1); // Cas: 1 3 2 -> 3 1 2 -> 1 2 3
	}
}


void	sorting_algo(t_stack *a, t_stack *b)
{
	if (a->size > 3 && !is_sorted(a))
		pb (a, b);
	if (a->size > 3 && !is_sorted(a))
		pb (a, b);
	
}
