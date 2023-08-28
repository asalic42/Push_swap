/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:08:53 by asalic            #+#    #+#             */
/*   Updated: 2022/11/16 10:32:32 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *memo, int search, size_t size)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = (unsigned char *)(memo);
	while (i < (int)size)
	{
		if (ptr[i] == (unsigned char)(search))
			return (ptr + i);
		i ++;
	}
	return (NULL);
}
