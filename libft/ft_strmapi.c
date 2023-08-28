/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:19 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:59:06 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc (((unsigned int)ft_strlen(s) + 1 * sizeof(char)));
	if (!str)
		return (NULL);
	while (i < (unsigned int)ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i ++;
	}
	str[i] = '\0';
	return (str);
}
