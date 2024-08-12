/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:30:30 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/11 16:37:00 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	long	max;
	t_stack	*max_stack;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_stack = stack;
		}
		stack = stack->next;
	}
	return (max_stack);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_stack;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_stack = stack;
		}
		stack = stack->next;
	}
	return (min_stack);
}

void	prepare_push(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	get_position(t_stack *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = (get_stack_size(stack) / 2);
	while (stack)
	{
		stack->pos = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

// t_stack	*get_cheapest(t_stack *stack)
// {
// 	long	smallest;
// 	t_stack	*cheapest;

// 	if (!stack)
// 		return (NULL);
// 	smallest = LONG_MAX;
// 	while (stack)
// 	{
// 		if (stack->cost < smallest)
// 		{
// 			smallest = stack->cost;
// 			cheapest = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (cheapest);
// }
t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	if (!stack)
		return (NULL);
	if (!stack->next)
		return (stack);
	cheapest = get_cheapest(stack->next);
	if (stack->cost < cheapest->cost)
		return (stack);
	else
		return (cheapest);
}
