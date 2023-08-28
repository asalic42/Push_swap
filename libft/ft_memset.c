/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:27:17 by asalic            #+#    #+#             */
/*   Updated: 2022/11/14 18:49:33 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

void	*ft_memset(void *spc, int value, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *) spc;
	while (i < n)
	{
		pt[i] = value;
		i ++;
	}
	return (spc);
}
