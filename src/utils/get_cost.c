/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:32:15 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/11 11:59:46 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_cost_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->pos;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - (stack_a->pos);
		if (stack_a->target->above_median)
			stack_a->cost += stack_a->target->pos;
		else
			stack_a->cost += len_b - (stack_a->target->pos);
		stack_a = stack_a->next;
	}
}

static void	get_target_b(t_stack *a, t_stack *b)
{
	t_stack	*temp_a;
	t_stack	*target_b;
	long	bigger;

	while (b)
	{
		bigger = LONG_MAX;
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->value > b->value && temp_a->value < bigger)
			{
				bigger = temp_a->value;
				target_b = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (bigger == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_b;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	get_position(a);
	get_position(b);
	get_target_b(a, b);
}

void	get_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	long	small;

	temp_a = stack_a;
	while (temp_a)
	{
		small = LONG_MIN;
		temp_b = stack_b;
		while (temp_b)
		{
			if (temp_a->value > temp_b->value && temp_b->value >= small)
			{
				small = temp_b->value;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (small == LONG_MIN)
			temp_a->target = find_max(stack_b);
		temp_a = temp_a->next;
	}
}

void	init_a(t_stack *a, t_stack *b)
{
	get_position(a);
	get_position(b);
	get_target_a(a, b);
	get_cost_a(a, b);
	get_cheapest(a);
}
