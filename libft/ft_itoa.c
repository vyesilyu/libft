/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/15 16:34:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numberofelements(int a)
{
	int	i;

	i = 0;
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

static void	strrev(char *s1, int elements)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = elements - 1;
	while (i < j)
	{
		temp = s1[i];
		s1[i] = s1[j];
		s1[j] = temp;
		i++;
		j--;
	}
}

static void	strassign(char *s1, int size, int n, int check)
{
	int	i;

	i = 0;
	while (i < size)
	{
		s1[i] = '0' + n % 10;
		n = n / 10;
		i++;
	}
	if (check)
	{
		s1[i] = '-';
		i++;
	}
	s1[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		check;
	int		size;
	char	*str;
	int		i;

	check = 0;
	if (n < 0)
	{
		check = 1;
		n *= -1;
	}
	size = numberofelements(n);
	str = (char *)malloc((size + check + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	strassign(str, size, n, check);
	strrev(str, size + check);
	return (str);
}
