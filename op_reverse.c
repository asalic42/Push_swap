/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:47:34 by asalic            #+#    #+#             */
/*   Updated: 2023/04/07 15:48:00 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// contient reverse_rotate_a(rra), reverse_rotate_b(rrb) et 
// reverse_rotate_ab(rrr)
t_list2	*reverse_rotate_a(t_list2 *lista)
{
	t_list2	*last;
	t_list2	*ptr;

	if (!lista || !lista->next)
		return (lista);
	ptr = lista;
	last = last_list(lista);
	addfront_list(&lista, last->data);
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	delback(lista);
	ptr->next = NULL;
	ft_printf("rra\n");
	return (lista);
}

t_list2	*reverse_rotate_b(t_list2 *listb)
{
	t_list2	*last;
	t_list2	*ptr;

	if (!listb || !listb->next)
		return (listb);
	ptr = listb;
	last = last_list(listb);
	addfront_list(&listb, last->data);
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	delback(listb);
	ptr->next = NULL;
	ft_printf("rrb\n");
	return (listb);
}

void	reverse_rotate_ab(t_list2 **lista, t_list2 **listb)
{
	*lista = reverse_rotate_a(*lista);
	*listb = reverse_rotate_b(*listb);
	ft_printf("rrr\n");
}
