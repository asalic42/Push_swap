/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:32:24 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:55:43 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	a;

	a = -1;
	i = 0;
	if (c == '\0')
		return ((char *)str + ft_strlen((char *)str));
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			a = i;
		i ++;
	}
	if (a > -1)
		return ((char *)str + a);
	return (NULL);
}
