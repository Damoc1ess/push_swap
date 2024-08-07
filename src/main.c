/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:22:00 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 19:48:41 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void which_sort(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		if (a->size == 2)
			sa(a, 1);
		else if (a->size == 3)
			sort_three_elements(a, b);
		else if (a->size > 3)
			sorting_algo(a, b);
	}
}

int count_elements(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int arg_count;
	int i;
	char **split_args;

	if (argc < 2)
		return (write(2, "Error: Not enough arguments\n", 28), (0));

	if (argc == 2)
	{
		arg_count = count_elements(argv[1], ' ');
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			return (write(2, "Error: Memory allocation failed\n", 32), (0));
	}
	else
	{
		split_args = argv + 1;
		arg_count = argc - 1;
	}
	if(check_args(split_args) == 1)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	read_input(&a, arg_count, split_args);
	init_stack(&b, a.size);
	printf("size of stack A : %d\n", a.size);//  NE PAS GARDER
	ft_print_stack(&a);                      //  NE PAS GARDER
	which_sort(&a, &b);
	ft_print_stack(&a);                      //  NE PAS GARDER
	free_stack(&a);
	free_stack(&b);

	if (argc == 2)
	{
		i = 0;
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
	}
	return (0);
}
