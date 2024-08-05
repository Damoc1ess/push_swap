#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack a, b;
	char **args;
	int arg_count;
	int i;

	if (argc < 2)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (0);
	}
	if (argc == 2)
		argv = ft_split(argv[1]);
	read_input(&a, argc, argv);
	init_stack(&b, a.size);
	ft_print_stack(&a);
	while (!is_sorted(&a))
	{
		if (a.size == 3)
			sort_three_elements(&a, &b);
	}
	ft_print_stack(&a);
	free_stack(&a);
	free_stack(&b);
	return 0;
}
