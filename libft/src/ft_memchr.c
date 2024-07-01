/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbiteau <cbiteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:14:33 by cbiteau          #+#    #+#             */
/*   Updated: 2024/05/07 14:41:03 by cbiteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*buffer;
	unsigned char		byte;
	size_t				i;

	byte = (unsigned char)c;
	buffer = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (buffer[i] == byte)
			return ((void *)(&buffer[i]));
		i++;
	}
	return (NULL);
}
