/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:04:49 by asalic            #+#    #+#             */
/*   Updated: 2023/04/06 17:41:41 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creation de la liste qui representera la pileA initale
void	addfront_list(t_list2 **lst, int data)
{
	t_cell	*cell;

	cell = create_cell(data);
	if (!lst || !*lst)
		*lst = cell;
	else
	{
		cell -> next = *lst;
		*lst = cell;
	}
}

t_list2	*last_list(t_list2 *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	last_init(t_list2 *list)
{
	int	init;

	init = 0;
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	init = list->data;
	return (init);
}

t_list2	*delback(t_list2 *lst)
{
	t_list2	*supp;

	supp = last_list(lst);
	free(supp);
	return (lst);
}

int	len_list(t_list2 *list)
{
	int	len;

	len = 0;
	while (list != NULL)
	{
		len ++;
		list = list->next;
	}
	return (len);
}
