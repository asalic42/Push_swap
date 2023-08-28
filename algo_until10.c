/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_until10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:41:37 by asalic            #+#    #+#             */
/*   Updated: 2023/04/21 12:18:17 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction qui renvoie correctement les elements de B dans A
void	back_ina(t_list2 **lista, t_list2 **listb, t_list2 *lista_init)
{
	int	lenb;
	int	small;

	small = smallest(lista_init);
	lenb = len_list(*listb);
	if (len_list(lista_init) == 2 && lista_init->data != small)
		*lista = swap_a(*lista);
	while (lenb != 0)
	{
		push_a(lista, listb, *listb);
		lenb --;
	}
}

// Check si pileA est rangee
t_bool	is_rangea(t_list2 *lista, t_list2 *listb)
{
	int	len;

	len = len_list(lista);
	while (len != 0 && lista->next)
	{
		if (lista->data > lista->next->data)
			return (false);
		if (!is_closer(lista, lista->data, lista->next->data))
			return (false);
		if (!is_closer(listb, lista->data, lista->next->data))
			return (false);
		lista = lista->next;
		len --;
	}
	return (true);
}

void	suit_code(t_list2 **lista, int big)
{
	if ((*lista)->data == big)
		*lista = rotate_a(*lista);
	else if ((*lista)->data > (*lista)->next->data && (*lista)->data
		< (*lista)->next->next->data)
		*lista = swap_a(*lista);
	while (last_list(*lista)->data < (*lista)->data)
		*lista = reverse_rotate_a(*lista);
}

// Code principal : de 11 a 49
t_list2	*main_code(t_list2 *lista, t_list2 *listb)
{
	int		big;

	big = biggest(lista);
	while (len_list(lista) != 0)
	{
		if (listb && is_rangea(lista, listb) && lista->data > biggest(listb))
			break ;
		if (!listb && is_rangea(lista, listb))
			break ;
		suit_code(&lista, big);
		if (!listb && is_rangea(lista, listb))
			break ;
		if (listb && is_rangea(lista, listb) && lista->data > biggest(listb))
			break ;
		where_pos(&lista, &listb, lista);
	}
	if (listb)
	{
		listb = replace_order(listb);
		back_ina(&lista, &listb, lista);
	}
	return (lista);
}
