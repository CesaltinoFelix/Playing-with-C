/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:54:48 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/09 11:54:52 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// state[0]: current position in buffer
// state[1]: buffer size
// state[2]: initialized?
//line[7000000] => Buffer to store the line to be returned.
// It's not the best pratice i could do
// but at the moment it help me to give the solution of this problem.
char	*get_next_line(int fd)
{
	static int	state[3];
	static char	buffer[BUFFER_SIZE];
	char		line[7000000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	initialize_state(state);
	while (1)
	{
		if (state[0] >= state[1])
			if (buffer_size(fd, buffer, &state[1], &state[0]) <= 0)
				break ;
		line[i++] = buffer[state[0]++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
