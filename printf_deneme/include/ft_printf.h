/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:41:01 by Vyesilyu          #+#    #+#             */
/*   Updated: 2023/10/29 15:46:43 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

// format functions
void	ft_printfchar(char c, size_t *counter);
void	ft_printfstr(char *str, size_t *counter);
void	ft_printfnbr(int num, size_t *counter);
void	ft_printfuint(unsigned int num, size_t *counter);
void	ft_printfhex(unsigned int num, size_t *counter, char *base);
void	ft_printfptr(void *ptr, size_t *counter);

// auxiliary functions
char	*ft_aux_pf(unsigned long long n, char *base);

#endif
