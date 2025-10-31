/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:36:14 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/10/31 14:43:06 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_storage(int fd, char *storage)
{
	char	*buf;
	char	*temp;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!storage)
		storage = ft_strjoin("", "");
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(storage), NULL);
		buf[bytes_read] = '\0';
		temp = ft_strjoin(storage, buf);
		free(storage);
		storage = temp;
		if (!storage)
			return (free(buf), NULL);
	}
	free(buf);
	return (storage);
}

static char	*extract_line(char *storage)
{
	size_t	i;
	char	*line;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_storage(char *storage)
{
	size_t	i;
	size_t	j;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (free(storage), NULL);
	i++;
	new_storage = malloc(ft_strlen(storage) - i + 1);
	if (!new_storage)
		return (free(storage), NULL);
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	return (free(storage), new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_to_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	storage = update_storage(storage);
	return (line);
}
