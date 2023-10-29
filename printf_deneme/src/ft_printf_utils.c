/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:45:19 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/29 15:46:28 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	ft_printfchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_printfstr(char *str, size_t *counter)
{
	if(!str)
		str = "(null)";
	while (*str)
	{
		ft_printfchar(*str, counter);
		str++;
	}
}

void	ft_printfnbr(int n, size_t *counter)
{
	char	*num;
	
	num = ft_itoa(n);
	ft_printfstr(num, counter);
}
