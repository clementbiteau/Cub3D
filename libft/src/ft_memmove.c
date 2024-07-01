/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbiteau <cbiteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:25:05 by cbiteau          #+#    #+#             */
/*   Updated: 2024/05/08 17:06:29 by cbiteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buffer_dest;
	int				i;

	if (dest == src || n == 0)
		return (dest);
	buffer_dest = (unsigned char *)dest;
	if (dest < src)
	{
		i = 0;
		while ((size_t)i < n)
		{
			buffer_dest[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (--i >= 0)
			buffer_dest[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}
