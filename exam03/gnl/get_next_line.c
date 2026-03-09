/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlundaev <vlundaev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:43:03 by vlundaev          #+#    #+#             */
/*   Updated: 2025/10/07 11:09:40 by vlundaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i = 0;
	char character;
	int rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	char *line = malloc(100000);

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(line);
		return (NULL);
	}

	while (rd > 0)
	{
		line[i] = character;
		i++;
		if (character == '\n')
			break ;
		rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	}
	if (rd == -1 || (rd == 0 && i == 0))
	{
		free (line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

