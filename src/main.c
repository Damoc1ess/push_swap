#include "../include/push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    t_stack a = {NULL, 0};
    t_stack b = {NULL, 0};

    read_input(&a, argc, argv);

    init_stack(&b, a.size);

    print_stack(&a, "a");
    print_stack(&b, "b");

    t_solution best_solution;
    best_solution.operations = malloc(a.size * sizeof(int));
    if (!best_solution.operations) {
        perror("malloc");
        return 1;
    }
    best_solution.op_count = INT_MAX;

    t_solution current_solution;
    current_solution.operations = malloc(a.size * sizeof(int));
    if (!current_solution.operations) {
        perror("malloc");
        free(best_solution.operations);
        return 1;
    }
    current_solution.op_count = 0;

    backtrack(&a, &b, &best_solution, &current_solution);

    printf("Meilleure solution trouvée avec %d opérations\n", best_solution.op_count);
    for (int i = 0; i < best_solution.op_count; i++) {
        printf("%d ", best_solution.operations[i]);
    }
    printf("\n");

    free_stack(&a);
    free_stack(&b);
    free(best_solution.operations);
    free(current_solution.operations);

    return 0;
}
