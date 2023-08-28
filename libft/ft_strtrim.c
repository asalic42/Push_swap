/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:43:38 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 10:59:26 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	ft_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s1 && *set)
	{
		while (s1[i] != set[j])
		{
			if (j == ft_strlen(set) - 1)
				return (i);
			j ++;
		}
		if (s1[i] == set[j])
			j = 0;
		i ++;
	}
	return (i);
}

static size_t	ft_end(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (i -1 > ft_start(s1, set) && *set)
	{
		while (s1[i -1] != set[j])
		{
			if (j == ft_strlen(set) - 1)
			{
				return (i);
			}
			j ++;
		}
		if (s1[i -1] == set[j])
			j = 0;
		i --;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	size_t		start;
	size_t		end;

	start = ft_start(s1, set);
	end = ft_end(s1, set);
	str = malloc(((end - start) + 1) * sizeof(*s1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
