/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbiteau <cbiteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:32 by cbiteau          #+#    #+#             */
/*   Updated: 2023/11/08 10:34:17 by cbiteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buffer1;
	unsigned char	*buffer2;
	size_t			i;

	if (n == 0)
		return (0);
	buffer1 = (unsigned char *)s1;
	buffer2 = (unsigned char *)s2;
	i = 0;
	while (i < n - 1 && buffer1[i] == buffer2[i])
		i++;
	return (buffer1[i] - buffer2[i]);
}
