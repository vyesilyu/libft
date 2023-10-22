/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:46:09 by eablak            #+#    #+#             */
/*   Updated: 2023/10/21 12:12:29 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_same(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_nan(char *all_arguments)
{
	int	i;

	i = 0;
	while (all_arguments[i])
	{
		if (all_arguments[i] == '-' && (all_arguments[i + 1] == '\0'
				|| all_arguments[i + 1] == ' '))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (!(all_arguments[i] >= 48 && all_arguments[i] <= 57)
			&& all_arguments[i] != '-' && all_arguments[i] != ' ')
		{
			write(2, "Error\n", 6);
			free(all_arguments);
			exit(1);
		}
		i++;
	}
}

void	check_sorted(int *arr, int size)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i;
		nbr = arr[i];
		while (j < size)
		{
			if (nbr > arr[j])
				return ;
			j++;
		}
		i++;
	}
	exit(1);
}
