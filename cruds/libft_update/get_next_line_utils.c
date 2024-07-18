/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:55:04 by cefelix           #+#    #+#             */
/*   Updated: 2024/06/09 11:55:11 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(i + 1);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Function to initialize the static variables
// (!state[2]) If the state[2] (initialization flag) is 0
// state[0] = 0; Initialize the current position in buffer
// state[1] = 0; Initialize the buffer size
// state[2] = 1; Mark as initialized
void	initialize_state(int *state)
{
	if (!state[2])
	{
		state[0] = 0;
		state[1] = 0;
		state[2] = 1;
	}
}

// Function to read data from the file and update the buffer
/*pos = 0; Reset the position in the buffer 'cause 
i need this information to verify if all caracter 
in buffer was read*/
int	buffer_size(int fd, char *buffer, int *size, int *pos)
{
	*size = read(fd, buffer, BUFFER_SIZE);
	*pos = 0;
	return (*size);
}
