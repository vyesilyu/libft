/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:59:40 by eablak            #+#    #+#             */
/*   Updated: 2023/10/18 18:33:29 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)s + gnl_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*united;
	size_t	j;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	united = (char *)malloc(sizeof(char) * gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (united == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		united[i] = s1[i];
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	free(s1);
	return (united);
}

char	*ft_bring(char *all_line)
{
	int		i;
	char	*send;

	i = 0;
	if (!all_line[i])
		return (NULL);
	while (all_line[i] != '\n' && all_line[i] != '\0')
		i++;
	send = (char *)malloc(sizeof(char) * (i + 2));
	if (!send)
		return (0);
	i = 0;
	while (all_line[i] != '\n' && all_line[i] != '\0')
	{
		send[i] = all_line[i];
		i++;
	}
	if (all_line[i] == '\n')
		send[i++] = '\n';
	send[i] = '\0';
	return (send);
}

char	*ft_take_rest(char *all_line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (all_line[i] != '\n' && all_line[i] != '\0')
		i++;
	if (!all_line[i])
	{
		free(all_line);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * gnl_strlen(all_line) - i + 1);
	if (!rest)
		return (0);
	i++;
	while (all_line[i] != '\0')
		rest[j++] = all_line[i++];
	rest[j] = '\0';
	free(all_line);
	return (rest);
}
