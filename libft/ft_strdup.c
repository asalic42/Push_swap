/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:30 by asalic            #+#    #+#             */
/*   Updated: 2022/11/23 14:48:26 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!(dup))
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}
