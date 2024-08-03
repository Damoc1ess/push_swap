#include "../include/push_swap.h"

void quicksort(t_stack *a, t_stack *b, t_solution *solution)
{
	if (a->size <= 1 || is_sorted(a))
		return;

	int pivot = a->data[a->size / 2];

	for (int i = 0; i < a->size; i++)
	{
		if (a->data[a->size - 1] <= pivot)
		{
			pb(a, b);
			add_operation(solution, PB);
		}
		else
		{
			ra(a);
			add_operation(solution, RA);
		}
	}

	quicksort(a, b, solution);

	while (b->size > 0)
	{
		pa(a, b);
		add_operation(solution, PA);
	}
}

void sort_stack(t_stack *a, t_stack *b)
{
	t_solution solution;
	solution.operations = malloc(a->size * 10 * sizeof(int));
	solution.op_count = 0;

	quicksort(a, b, &solution);

	char buf[50];
	int len = snprintf(buf, sizeof(buf), "Total operations: %d\n", solution.op_count);
	write(1, buf, len);
	free(solution.operations);
}
