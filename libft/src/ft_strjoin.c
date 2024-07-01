/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbiteau <cbiteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:50:16 by cbiteau          #+#    #+#             */
/*   Updated: 2024/02/16 14:21:20 by cbiteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, s1_len + 1);
	ft_strlcat(buffer, s2, s1_len + s2_len + 1);
	return (buffer);
}

static size_t	calculate_total_length(const char *str, va_list args)
{
	size_t	length;

	length = 0;
	while (str)
	{
		length += ft_strlen(str);
		str = va_arg(args, const char *);
	}
	return (length);
}

char	*ft_strsjoin(const char *str, ...)
{
	va_list	args;
	char	*res;
	size_t	len;

	if (!str)
		return (NULL);
	va_start(args, str);
	len = calculate_total_length(str, args);
	va_end(args);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = 0;
	va_start(args, str);
	while (str)
	{
		ft_strcat(res, str);
		str = va_arg(args, const char *);
	}
	va_end(args);
	return (res);
}

char	*ft_strsjoin_array(const char **strs)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (strs[i])
	{
		len += ft_strlen(strs[i++]);
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (strs[i])
		ft_strcat(str, strs[i++]);
	return (str);
}
