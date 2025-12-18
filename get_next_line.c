/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:43:06 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/25 06:47:39 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)tab)[i] = '\0';
		i++;
	}
}

int	ft_strlen(char *s)
{
	int	index;

	index = -1;
	while (*(s + (++index)))
		;
	return (index);
}

char	*ft_nomore(char **buffer, char **line)
{
	free(*buffer);
	if (**line)
		return (*line);
	free(*line);
	return (NULL);
}

int	ft_alloc(char **buffer, char **line, char **next, int *nb_read)
{
	*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(*buffer))
		return (-1);
	if (*next)
	{
		*line = ft_strdup(*next);
		free(*next);
		*next = NULL;
	}
	else
		*line = ft_calloc(1, sizeof(char));
	*nb_read = 1;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*line;
	char		*buffer;
	int			nb_read;
	int			i;

	i = ft_alloc(&buffer, &line, &next, &nb_read);
	if (i == -1)
		return (NULL);
	while ((ft_strchr(line, '\n') == NULL) && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free(buffer), free(line), NULL);
		line = ft_strjoin(line, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	if (nb_read == 0)
		return (ft_nomore(&buffer, &line));
	while (line[i] && line[i] != '\n')
		i++;
	next = ft_strdup(&line[i + 1]);
	line = ft_strndup(&line, i + 1);
	free(buffer);
	return (line);
}

/* #include <stdio.h>
int main(void){
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		free(str);
	}
	close(fd);
} */