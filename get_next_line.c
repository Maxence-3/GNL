/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:06 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/19 03:57:57 by mde-carv         ###   ########.fr       */
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

void	ft_realloc(void *ptr, size_t new_size)
{
	char	*new_ptr;

	new_ptr = malloc(sizeof(char *) * new_size);
	// if (!new_ptr)
	// 	return (NULL);
	memcpy(new_ptr, ptr, new_size);
	free(ptr);
	ptr = new_ptr;
}

char	*get_next_line(int fd)
{
	char	current;
	char	*line;
	int 	nb_read;
	int		i;

	if (fd == -1)
		return (NULL);
	line = malloc(sizeof(char *));
	if (!line)
		return (NULL);
	nb_read = read(fd, &current, 1);
	i = 0;
	while (current != '\n' && nb_read != 0)
	{
		line[i] = current;
		i++;
		nb_read = read(fd, &current, 1);
		ft_realloc(line, i);
	}
	line[i] = '\0';
	return(line);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char * test = get_next_line(fd);
	ft_putstr(test);
	free(test);
/* 	test = get_next_line(fd);
	free(test); */
	close(fd);
}