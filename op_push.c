/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:45:39 by asalic            #+#    #+#             */
/*   Updated: 2023/04/13 11:19:52 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// contient push_a(pa) et push_b(pb)
void	push_a(t_list2 **lista, t_list2 **listb, t_list2 *listb_init)
{
	if (!(listb_init))
		return ;
	addfront_list(lista, listb_init->data);
	*listb = free_list (*listb, 0);
	ft_printf("pa\n");
}

void	push_b(t_list2 **lista, t_list2 **listb, t_list2 *lista_init)
{
	if (!(lista_init))
		return ;
	addfront_list(listb, lista_init->data);
	*lista = free_list (*lista, 0);
	ft_printf("pb\n");
}
