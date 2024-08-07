/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:05:33 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 13:32:25 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void read_input(t_stack *a, int arg_count, char **argv)
{
	int	i = 0;
	// Initialisez la pile a avec les valeurs des arguments
	a->size = arg_count;
	a->data = malloc(sizeof(int) * arg_count);
	if (!a->data)
		return;

	while (i < arg_count)
	{
		a->data[i] = atoi(argv[i]); 
		i++;
	}
}

void init_stack(t_stack *stack, int size)
{
	stack->size = size;
	stack->data = malloc(sizeof(int) * size);
	if (!stack->data)
		return;
}

void ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("-----\n");
	while (i < stack->size)
		printf("| %d |\n", stack->data[i++]);
	printf("-----\n");
}

void free_stack(t_stack *stack)
{
	free(stack->data);
	stack->size = 0;
}

int is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return 0;
		i++;
	}
	return 1;
}

void swap(t_stack *a, int i, int j)
{
	int temp = a->data[i];
	a->data[i] = a->data[j];
	a->data[j] = temp;
}
