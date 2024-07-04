/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbiteau <cbiteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:23:26 by cbiteau          #+#    #+#             */
/*   Updated: 2024/02/06 16:15:04 by cbiteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	byte;

	byte = (unsigned char)c;
	while (*s != '\0' && *s != byte)
		s++;
	if (*s == byte)
		return ((char *)s);
	return (NULL);
}
