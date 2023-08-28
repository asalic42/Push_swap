/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:41:11 by asalic            #+#    #+#             */
/*   Updated: 2022/11/25 08:54:26 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		len_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = ft_intlen(n);
	nbr = malloc((len_n + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	i = 1;
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	nbr[len_n] = '\0';
	while (n > 9)
	{
		nbr[len_n - i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	nbr[len_n - i] = n + 48;
	return (nbr);
}
