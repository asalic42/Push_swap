/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:32 by asalic            #+#    #+#             */
/*   Updated: 2022/11/15 15:15:57 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (s1[0] == '\0' && i < len)
		return (- ((unsigned char *)s2)[0]);
	if (s2[0] == '\0' && i < len)
		return (((unsigned char *)s1)[0]);
	while ((s2[i] || s1[i]) && i < len)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i ++;
	}
	return (0);
}
