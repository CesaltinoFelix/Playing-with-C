/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:41:09 by cefelix           #+#    #+#             */
/*   Updated: 2024/05/14 12:41:12 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	length_s;
	size_t	i;

	length_s = ft_strlen(s);
	if (start >= length_s)
		return (ft_strdup(""));
	if (length_s - start < len)
		len = length_s - start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = -1;
	while (s[++i + start] && (i < len))
		substring[i] = s[start + i];
	substring[len] = '\0';
	return (substring);
}
