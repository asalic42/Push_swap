/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:04:27 by asalic            #+#    #+#             */
/*   Updated: 2023/04/06 17:51:11 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compteur jusqu'au nb
int	counter(t_list2 *list, int nb)
{
	int	count;

	count = 0;
	while (list->data != nb)
	{
		count ++;
		list = list->next;
	}
	return (count);
}

t_list2	*first_pos(t_list2 *lista)
{
	lista = reverse_rotate_a(lista);
	lista = swap_a(lista);
	return (lista);
}

t_list2	*reverse_order(t_list2 *lista)
{
	lista = rotate_a(lista);
	lista = swap_a(lista);
	return (lista);
}

t_list2	*check_algo2(t_list2 *lista)
{
	if (lista->data > lista->next->data)
		lista = swap_a(lista);
	return (lista);
}

t_list2	*check_algo3(t_list2 *lista)
{
	if (lista->data < lista->next->data && lista->next->data < lista->next
		->next->data)
		return (lista);
	else if (lista->data < lista->next->data && lista->data < lista->next->next
		->data)
		lista = first_pos(lista);
	else if (lista->data < lista->next->data && lista->data > lista->next->next
		->data)
		lista = reverse_rotate_a(lista);
	else if (lista->data > lista->next->data && lista->data > lista->next->next
		->data && lista->next->data < lista->next->next->data)
		lista = rotate_a(lista);
	else if (lista->data > lista->next->data && lista->data < lista->next->next
		->data)
		lista = swap_a(lista);
	else if (lista->data > lista->next->data && lista->next->data > lista->next
		->next->data)
		lista = reverse_order(lista);
	return (lista);
}
