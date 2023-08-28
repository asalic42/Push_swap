/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:46:26 by asalic            #+#    #+#             */
/*   Updated: 2023/04/07 15:47:54 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// contient rotate_a(ra), rotate_b(rb) et rotate_ab(rr) avec des listes !!
t_list2	*rotate_a(t_list2 *lista)
{
	t_list2	*tmp;
	t_list2	*last;

	if (!lista || !lista->next)
		return (lista);
	tmp = lista;
	last = last_list(lista);
	lista = lista->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
	return (lista);
}

t_list2	*rotate_b(t_list2 *listb)
{
	t_list2	*tmp;
	t_list2	*last;

	if (!listb || !listb->next)
		return (listb);
	tmp = listb;
	last = last_list(listb);
	listb = listb->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
	return (listb);
}

void	rotate_ab(t_list2 **lista, t_list2 **listb)
{
	*lista = rotate_a(*lista);
	*listb = rotate_b(*listb);
	ft_printf("rr\n");
}
