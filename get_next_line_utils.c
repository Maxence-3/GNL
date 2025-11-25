/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-carv <mde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:44:43 by mde-carv          #+#    #+#             */
/*   Updated: 2025/11/25 03:02:42 by mde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(sizeof(char) * len + 1);
	if (string == NULL)
		return (NULL);
	while (s1[i])
	{
		string[++j] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		string[++j] = s2[i];
		i++;
	}
	free(s1);
	string[++j] = '\0';
	return (string);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(src);
	i = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strndup(char **src, size_t n)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(*src);
	i = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while ((*src)[i] && (size_t)i < n)
	{
		str[i] = (*src)[i];
		i++;
	}
	free(*src);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	caracter;
	int		i;

	caracter = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == caracter)
			return ((s) + i);
		i++;
	}
	if (caracter == '\0')
		return ((s) + i);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	total_size;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
