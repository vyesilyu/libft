/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:45:19 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/29 14:47:15 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	ft_printchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_printstr(char *str, size_t *counter)
{
	if(!str)
		str = "(null)";
	while (*str)
	{
		ft_printchar(*str, counter);
		str++;
	}
}

void	ft_printnbr(int n, size_t *counter)
{
	char	*num;
	
	num = ft_itoa(n);
	ft_printstr(num, counter);
}
