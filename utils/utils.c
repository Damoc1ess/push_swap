/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:12:01 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/03 16:53:05 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void read_input(t_stack *a, int argc, char **argv)
{
	a->data = malloc((argc - 1) * sizeof(int));
	a->size = 0;
	for (int i = 1; i < argc; i++)
	{
		a->data[a->size++] = atoi(argv[i]);
	}
}

void print_stack(t_stack *stack, const char *name)
{
	printf("Pile %s: ", name);
	for (int i = 0; i < stack->size; i++)
	{
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}

int evaluate_solution(t_stack *a)
{
	return 0;
}

void free_stack(t_stack *stack)
{
	free(stack->data);
}

void init_stack(t_stack *stack, int size)
{
	stack->data = malloc(size * sizeof(int));
	stack->size = 0;
}

void copy_stack(t_stack *dest, t_stack *src)
{
	dest->size = src->size;
	for (int i = 0; i < src->size; i++)
	{
		dest->data[i] = src->data[i];
	}
}

void undo_operation(t_stack *a, t_stack *b, int op)
{
}

int is_sorted(t_stack *a)
{
    int i;

    if (a->size <= 1)
        return 1;
    for (i = 0; i < a->size - 1; i++)
    {
        if (a->data[i] > a->data[i + 1])
            return 0;
    }
    return 1;
}
