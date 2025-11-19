/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:06 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/19 06:57:29 by mde-carv         ###   ########.fr       */
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

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	ft_memcpy(new_ptr, ptr, new_size - 1);
	free(ptr);
	return (new_ptr);
}

char	*get_next_line(int fd)
{
	char	current;
	char	*line;
	int 	nb_read;
	int		i;

	if (fd == -1)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	nb_read = read(fd, &current, 1);
	i = 0;
	while (current != '\n' && nb_read != 0)
	{
		line[i] = current;
		i++;
		nb_read = read(fd, &current, 1);
		line = ft_realloc(line, i + 1);
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
	close(fd);
}