/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:44:10 by asalic            #+#    #+#             */
/*   Updated: 2023/04/07 15:47:43 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// contient swap_a(sa), swap_b(sb) et swap_ab(ss)
t_list2	*swap_a(t_list2 *lista)
{
	int	tmp;

	if (!lista || !lista->next)
		return (lista);
	tmp = lista->data;
	lista->data = lista->next->data;
	lista->next->data = tmp;
	ft_printf("sa\n");
	return (lista);
}

t_list2	*swap_b(t_list2 *listb)
{
	int	tmp;

	if (!listb || !listb->next)
		return (listb);
	tmp = listb->data;
	listb->data = listb->next->data;
	listb->next->data = tmp;
	ft_printf("sb\n");
	return (listb);
}

void	swap_ab(t_list2 **lista, t_list2 **listb)
{
	*lista = swap_a(*lista);
	*listb = swap_b(*listb);
	ft_printf("ss\n");
}
