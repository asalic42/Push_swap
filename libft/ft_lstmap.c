/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:56:32 by asalic            #+#    #+#             */
/*   Updated: 2022/11/24 11:11:26 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*liste;

	if (!lst || !f || !del)
		return (NULL);
	liste = ft_lstnew(f((void *)lst->content));
	if (!liste)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&liste, ft_lstnew(f((void *)lst->content)));
		if (!(liste))
		{
			ft_lstclear(&liste, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (liste);
}
