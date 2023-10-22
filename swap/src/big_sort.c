/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:21:08 by eablak            #+#    #+#             */
/*   Updated: 2023/10/21 13:18:54 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sendb_first_else(t_struct **struct_a, int *first, t_struct **keep_a)
{
	*keep_a = (*struct_a);
	(*first) = 1;
}

int	sendb_first(t_struct **struct_a, t_struct **struct_b, int size)
{
	t_struct	*keep_a;
	int			i;
	int			_pb;
	int			first;

	i = 0;
	_pb = 0;
	first = 0;
	while (i < size)
	{
		if ((*struct_a)->index < (size / 2))
		{
			pb(struct_a, struct_b);
			_pb++;
		}
		else
		{
			if (first == 0)
				sendb_first_else(struct_a, &first, &keep_a);
			ra(struct_a);
		}
		i++;
	}
	(*struct_a) = keep_a;
	return (_pb++);
}

void	send_second(t_struct **struct_a, t_struct **struct_b, int size,
		int *_pb)
{
	int	a_size;
	int	i;
	int	j;

	a_size = get_size_struct(struct_a);
	i = 0;
	j = 0;
	while (i < a_size)
	{
		if (((*struct_a)->index == size || (*struct_a)->index == size - 1
				|| (*struct_a)->index == size - 2) && j != 3)
		{
			ra(struct_a);
			j++;
		}
		else
		{
			pb(struct_a, struct_b);
			(*_pb)++;
		}
		i++;
	}
}

void	endb(t_struct **strc, int size)
{
	t_struct	*kp;
	int			i;

	i = 0;
	kp = (*strc);
	while (i < size)
	{
		if (i == size - 1)
		{
			(*strc)->next = NULL;
			break ;
		}
		(*strc) = (*strc)->next;
		i++;
	}
	(*strc) = kp;
}

void	big_sort(t_struct **struct_a, int size)
{
	t_struct	*struct_b;
	int			_pb;
	int			i;

	struct_b = NULL;
	_pb = 0;
	i = 0;
	if (size > 6)
		_pb = sendb_first(struct_a, &struct_b, size);
	send_second(struct_a, &struct_b, size, &_pb);
	endb(&struct_b, _pb);
	if (!is_sorted(*struct_a))
		little_sort(struct_a);
	while (struct_b)
	{
		position_processes(struct_a, &struct_b);
		get_const(struct_a, &struct_b);
		placement(struct_a, &struct_b);
	}
	if (!is_sorted(*struct_a))
		ascending(struct_a, size);
}
