/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:06 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/20 17:10:51 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		d[n] = s[n];
	return (dest);
}

int	check(int nb_read, char *buf)
{
	if (nb_read == -1)
	{
		free(buf);
		return (0);
	}
	return (1);
}

int	is_containt_backline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char *save;
	int			nb_read;
	char		*buf;
	char		*line;
	char		*res;
	
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (*save)
		line = ft_strdup(save);
	else
		line = ft_strdup("");
	while (!is_containt_backline(line))
	{	
		nb_read = read(fd, buf, sizeof(char) * BUFFER_SIZE);
		if (check(nb_read, buf))
			return ("NON !");
		line = ft_strjoin(line, buf);
		ft_bzero(buf, BUFFER_SIZE);
	}
	save = ft_strdup(&line[i]);
	res = ft_strndup();
	free(buf);
	return (res);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char * test;
	// int i = 0;
	test = get_next_line(fd);
	ft_putstr(test);
	free(test);
	// while (i < 3)
	// {
	// 	test = get_next_line(fd);
	// 	ft_putstr(test);
	// 	free(test);
	// 	i++;
	// }
	close(fd);
}