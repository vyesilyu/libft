/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:47:43 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/29 16:02:16 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_printfchar(va_arg(va, int), counter);
	else if (*str == 's')
		ft_printfstr(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_printfptr(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_printfnbr(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_printfuint(va_arg(va, int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'X')
			ft_printfhex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
		else
			ft_printfhex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);	
	}
	else if (*str == '%')
		ft_printfchar(*str,counter);
}

int		ft_printf(char const *str, ...)
{
	va_list		va;
	size_t		counter;
	
	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va,(char *)str, &counter);
		}
		else
			ft_printfchar(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}