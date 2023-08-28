/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:02:49 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:58:06 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc ((ft_strlen((char *)s1) + ft_strlen((char *)s2))
			+ 1 * sizeof(char));
	if (!(str))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j])
	{
		str[i++] = s2[j];
		j ++;
	}
	str[i] = '\0';
	return (str);
}
