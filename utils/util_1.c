#include "../include/push_swap.h"

void print_stack(t_stack *stack, const char *name)
{
    write(1, "Pile ", 5);
    write(1, name, 1);
    write(1, ": ", 2);
    for (int i = 0; i < stack->size; i++)
    {
        char buffer[12];
        int len = snprintf(buffer, sizeof(buffer), "%d ", stack->data[i]);
        write(1, buffer, len);
    }
    write(1, "\n", 1);
}

void read_input(t_stack *a, int argc, char **argv)
{
    a->data = malloc((argc - 1) * sizeof(int));
    a->size = 0;
    for (int i = 1; i < argc; i++)
    {
        a->data[a->size++] = atoi(argv[i]);
    }
}

void init_stack(t_stack *stack, int size)
{
    stack->data = malloc(size * sizeof(int));
    stack->size = 0;
}

void free_stack(t_stack *stack)
{
    free(stack->data);
}

int is_sorted(t_stack *a)
{
    for (int i = 0; i < a->size - 1; i++)
    {
        if (a->data[i] > a->data[i + 1])
            return 0;
    }
    return 1;
}

void apply_operation(t_stack *a, t_stack *b, int op)
{
    if (op == SA) sa(a);
    else if (op == SB) sb(b);
    else if (op == SS) ss(a, b);
    else if (op == PA) pa(a, b);
    else if (op == PB) pb(a, b);
    else if (op == RA) ra(a);
    else if (op == RB) rb(b);
    else if (op == RR) rr(a, b);
    else if (op == RRA) rra(a);
    else if (op == RRB) rrb(b);
    else if (op == RRR) rrr(a, b);
}

void add_operation(t_solution *solution, int op)
{
    solution->operations[solution->op_count++] = op;
}

void copy_solution(t_solution *dest, t_solution *src)
{
    dest->op_count = src->op_count;
    for (int i = 0; i < src->op_count; i++)
    {
        dest->operations[i] = src->operations[i];
    }
}
