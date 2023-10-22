/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vyesilyu <Vyesilyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:55:42 by eablak            #+#    #+#             */
/*   Updated: 2023/10/22 21:20:52 by Vyesilyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *all_line)
{
	char	*buf;
	int		return_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	return_read = 1;
	while ((!gnl_strchr(all_line, '\n')) && return_read != 0)
	{
		return_read = read(fd, buf, BUFFER_SIZE);
		if (return_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[return_read] = '\0';
		all_line = gnl_strjoin(all_line, buf);
	}
	free(buf);
	return (all_line);
}

char	*get_next_line(int fd)
{
	static char	*all_line;
	char		*wanted;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all_line = ft_get_line(fd, all_line);
	if (!all_line)
		return (NULL);
	wanted = ft_bring(all_line);
	all_line = ft_take_rest(all_line);
	return (wanted);
}


int main()
{
	int fd = open("a.txt", O_RDONLY, 0777);
	char *str = get_next_line(fd);
	int i = 0;
	while(str)
	{
		free(str);
		printf("%s",str);
		str = get_next_line(fd);
	}
}