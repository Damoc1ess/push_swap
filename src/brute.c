#include "../include/push_swap.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Applique une opération donnée sur les piles a et b
void apply_operation(t_stack *a, t_stack *b, int op) {
    if (op == SA) {
        sa(a);
        printf("sa\n");
    } else if (op == SB) {
        sb(b);
        printf("sb\n");
    } else if (op == SS) {
        ss(a, b);
        printf("ss\n");
    } else if (op == PA) {
        pa(a, b);
        printf("pa\n");
    } else if (op == PB) {
        pb(a, b);
        printf("pb\n");
    } else if (op == RA) {
        ra(a);
        printf("ra\n");
    } else if (op == RB) {
        rb(b);
        printf("rb\n");
    } else if (op == RR) {
        rr(a, b);
        printf("rr\n");
    } else if (op == RRA) {
        rra(a);
        printf("rra\n");
    } else if (op == RRB) {
        rrb(b);
        printf("rrb\n");
    } else if (op == RRR) {
        rrr(a, b);
        printf("rrr\n");
    }
}

// Annule une opération donnée sur les piles a et b
void undo_operation(t_stack *a, t_stack *b, int op) {
    if (op == SA) {
        sa(a); // L'inverse de SA est SA
    } else if (op == SB) {
        sb(b); // L'inverse de SB est SB
    } else if (op == SS) {
        ss(a, b); // L'inverse de SS est SS
    } else if (op == PA) {
        pb(a, b); // L'inverse de PA est PB
    } else if (op == PB) {
        pa(a, b); // L'inverse de PB est PA
    } else if (op == RA) {
        rra(a); // L'inverse de RA est RRA
    } else if (op == RB) {
        rrb(b); // L'inverse de RB est RRB
    } else if (op == RR) {
        rrr(a, b); // L'inverse de RR est RRR
    } else if (op == RRA) {
        ra(a); // L'inverse de RRA est RA
    } else if (op == RRB) {
        rb(b); // L'inverse de RRB est RB
    } else if (op == RRR) {
        rr(a, b); // L'inverse de RRR est RR
    }
}

// Fonction de backtracking pour trouver la meilleure séquence d'opérations
void backtrack(t_stack *a, t_stack *b, t_solution *best_solution, t_solution *current_solution) {
    // Vérifie si la pile a est triée
    if (is_sorted(a)) {
        // Si la solution actuelle utilise moins d'opérations que la meilleure solution trouvée
        if (current_solution->op_count < best_solution->op_count) {
            best_solution->op_count = current_solution->op_count;
            memcpy(best_solution->operations, current_solution->operations, current_solution->op_count * sizeof(int));
        }
        return;
    }

    // Limite de profondeur pour éviter une exploration excessive (optionnel)
    if (current_solution->op_count >= best_solution->op_count)
        return;

    // Essayer chaque opération possible
    for (int op = 0; op < NUM_OPERATIONS; op++) {
        // Appliquer l'opération
        apply_operation(a, b, op);
        
        // Ajouter l'opération à la solution actuelle
        current_solution->operations[current_solution->op_count++] = op;

        // Appel récursif
        backtrack(a, b, best_solution, current_solution);

        // Retirer l'opération de la solution actuelle
        current_solution->op_count--;
        
        // Annuler l'opération
        undo_operation(a, b, op);
    }
}
