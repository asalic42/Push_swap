/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:45:33 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:58:23 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	i;

	len_dest = 0;
	while (len_dest < size && dest[len_dest])
		len_dest ++;
	if (size == 0 || size <= len_dest)
		return (size + ft_strlen((char *)src));
	i = 0;
	while (src[i] && len_dest + i < size -1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (size != 0)
		dest[len_dest + i] = '\0';
	return (len_dest + ft_strlen((char *)src));
}
