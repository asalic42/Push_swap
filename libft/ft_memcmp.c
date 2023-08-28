/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:12:24 by asalic            #+#    #+#             */
/*   Updated: 2022/11/15 12:06:39 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	unsigned char		*ptr2;

	ptr = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < len)
	{
		if (ptr[i] != ptr2[i])
			return (ptr[i] - ptr2[i]);
		i ++;
	}
	return (0);
}
