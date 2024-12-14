/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:41:09 by cefelix           #+#    #+#             */
/*   Updated: 2024/05/14 12:41:12 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocd_mem;

	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (NULL);
	allocd_mem = (void *) malloc (nmemb * size);
	if (allocd_mem == NULL)
		return (NULL);
	ft_bzero(allocd_mem, nmemb * size);
	return (allocd_mem);
}
