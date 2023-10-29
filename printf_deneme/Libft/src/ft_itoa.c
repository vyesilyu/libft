/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:26 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/20 21:02:13 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long long a)
{
	int	i;

	i = 0;
	if (a <= 0)
	{
		i = 1;
	}
	while (a != 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			size;
	char		*str;

	num = n;
	size = count_digits(num);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	size--;
	if (num == 0)
		str[size] = '0';
	while (num)
	{
		str[size] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return (str);
}
