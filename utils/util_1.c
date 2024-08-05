#include "../include/push_swap.h"

void read_input(t_stack *a, int argc, char **argv)
{
    int i;

    a->data = (int *)malloc((argc - 1) * sizeof(int));
    if (!a->data)
        exit(1);
    a->size = argc - 1;
    i = 0;
    while (i < argc - 1)
    {
        a->data[i] = atoi(argv[i + 1]);
        i++;
    }
}

void init_stack(t_stack *b, int size)
{
    b->data = (int *)malloc(size * sizeof(int));
    if (!b->data)
        exit(1);
    b->size = 0;
}

void free_stack(t_stack *a)
{
    free(a->data);
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