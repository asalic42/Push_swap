/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:40:56 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 16:42:09 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count == 0 || size == 0)
		return (malloc(0));
	if ((__SIZE_MAX__ / size > count) && size > 0)
	{
		tab = malloc(count * size);
		if (!(tab))
			return (NULL);
		ft_bzero(tab, count * size);
		return (tab);
	}
	return (NULL);
}
