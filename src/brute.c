/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:34:03 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/03 16:27:22 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void apply_operation(t_stack *a, t_stack *b, int op)
{
    (void)a;
    (void)b;
    (void)op;
}

void undo_operation(t_stack *a, t_stack *b, int op)
{
    (void)a;
    (void)b;
    (void)op;
}


void backtrack(t_stack *a, t_stack *b, t_solution *best_solution, t_solution *current_solution) {
    if (is_sorted(a)) {
        int cost = evaluate_solution(a);
        if (cost < best_solution->op_count) {
            best_solution->op_count = cost;

            int i = 0;
            while (i < current_solution->op_count) {
                best_solution->operations[i] = current_solution->operations[i];
                i++;
            }
            best_solution->op_count = current_solution->op_count;
        }
        return;
    }

    int op = 0;
    while (op < NUM_OPERATIONS) {
        apply_operation(a, b, op);
        
        current_solution->operations[current_solution->op_count] = op;
        current_solution->op_count++;

        backtrack(a, b, best_solution, current_solution);

        current_solution->op_count--;
        undo_operation(a, b, op);

        op++;
    }
}
