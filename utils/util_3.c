/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:07:25 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 21:08:54 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **split_args)
{
	int	i;
	
	i = 0;
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
}