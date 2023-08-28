/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:27:07 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:56:34 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	if (dest < src)
		ft_memcpy (dest, src, n);
	else
	{
		while ((int)i > -1)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i --;
		}
	}
	return (dest);
}
