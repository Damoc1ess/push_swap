/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:09:09 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/06 13:49:47 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr_red(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, &str, i);
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

void	ft_print_stack(t_stack *a)
{
	int	i;

	i = 0;
	printf("-------\n");
	while (i <= a->size - 1)
	{
		printf("   %d\n", a->data[i]);
		i++;
	}
	printf("-------\n");
}
