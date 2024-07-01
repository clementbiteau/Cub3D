/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbiteau <cbiteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:01:08 by cbiteau          #+#    #+#             */
/*   Updated: 2024/05/30 12:44:47 by cbiteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	t_list	*substring_list;
	size_t	len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	substring_list = parse_format(format, args);
	if (!substring_list)
		return (-1);
	va_end(args);
	ft_lstiter(substring_list, (void *)put_substring_result);
	len = get_len_substrings(substring_list);
	ft_lstclear(&substring_list, (void *)free_substring);
	return (len);
}
