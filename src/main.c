#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(2, "Error: Not enough arguments\n", 28);
        exit(EXIT_FAILURE);
    }

    t_stack a, b;
    read_input(&a, argc, argv);
    init_stack(&b, a.size);

    if (!is_sorted(&a))
    {
        sort_stack(&a, &b);
    }
    free_stack(&a);
    free_stack(&b);
    return 0;
}
