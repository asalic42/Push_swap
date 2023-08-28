/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:27:17 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:58:33 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	if ((int)size < 0)
	{
		i = 0;
		while (src[i])
		{
			dest[i] = src[i];
			i ++;
		}
	}
	else
	{
		i = 0;
		while (i < (int)size - 1 && src[i])
		{
			dest[i] = src[i];
			i ++;
		}
	}
	if (size != 0)
		dest[i] = '\0';
	return (ft_strlen((char *)src));
}
