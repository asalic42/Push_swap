/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:56:23 by asalic            #+#    #+#             */
/*   Updated: 2022/11/23 15:01:07 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;
	int	i;

	i = 1;
	len = ft_lstsize(lst);
	while (i < len)
	{
		lst = lst -> next;
		i ++;
	}
	return (lst);
}
