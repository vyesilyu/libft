/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:11:00 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/29 15:47:09 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_baselen(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_aux_pf(unsigned long long n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;
	
	num_len = ft_baselen(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len -= 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

void	ft_printfhex(unsigned int num, size_t *counter, char *base)
{
	char	*str;
	str = ft_aux_pf(num, base);
	ft_printfstr(str, counter);
	free(str);
}

void	ft_printfptr(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_printfstr("0x", counter);
	str = ft_aux_pf(ptr_address, HEX_LOW_BASE);
	ft_printfstr(str, counter);
	free(str);
}
void	ft_printfuint(unsigned int num, size_t *counter)
{
	char	*str;
	
	str = ft_aux_pf(num, "0123456789");
	ft_printfstr(str, counter);
	free(str);
}