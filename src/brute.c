/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:53:19 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 13:07:04 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three_elements(t_stack *a, t_stack *b)
{
	if (a->data[0] > a->data[1] && a->data[0] < a->data[2])
		sa(a); // Cas: 2 1 3 -> 1 2 3
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		sa(a);
		rra(a); // Cas: 3 2 1 -> 2 3 1 -> 1 2 3
	}
	else if (a->data[0] > a->data[1] && a->data[0] > a->data[2])
		ra(a); // Cas: 3 1 2 -> 1 2 3
	else if (a->data[0] < a->data[1] && a->data[0] > a->data[2])
		rra(a); // Cas: 2 3 1 -> 1 2 3
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2])
	{
		sa(a);
		ra(a); // Cas: 1 3 2 -> 3 1 2 -> 1 2 3
	}
}
