/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:15:26 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:57:21 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)str + ft_strlen((char *)str));
	while (str[i])
	{
		if (str[i] == c % 128)
			return ((char *)str + i);
		i ++;
	}
	return (NULL);
}
