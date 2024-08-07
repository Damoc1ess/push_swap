/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:09:09 by fflamion          #+#    #+#             */
/*   Updated: 2024/08/07 20:01:56 by fflamion         ###   ########.fr       */
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


int		ft_atoi(const char *str)
{
	int neg;
	int i;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	nbr_cmp(char *str1, char *str2)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str1[i] == '0' || str1[i] == '-' || str1[i] == '+')
		i++;
	while (str2[j] == '0' || str2[j] == '-' || str2[j] == '+')
		j++;
	if (str1[i] != str2[j])
		return (0);
	while (str1[i] == str2[j] && str1[i])
	{
		i++;
		j++;
		if (str1[i] != str2[j])
			return (0);
	}
	return (1);
}
int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **tab)
{
	int		i;
	int		j;
	
	i = 0;
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]))
			return (1);
		i++;
	}
	i = 0;
	while (tab[i + 1])
	{

		j = i + 1;
		while (tab[j])
		{
			if (nbr_cmp(tab[i], tab[j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

