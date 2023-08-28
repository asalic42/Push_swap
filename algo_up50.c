/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_up50.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:57:17 by asalic            #+#    #+#             */
/*   Updated: 2023/04/13 12:14:31 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction qui va placer l'element de A au bon endroit dans B
void	where_pos(t_list2 **lista, t_list2 **listb, t_list2 *lista_init)
{
	int	pos;

	pos = pos_dest(*listb, lista_init->data);
	if (pos > 2)
	{
		*listb = rotate_pileb(*listb, pos);
		push_b(lista, listb, lista_init);
	}
	else if (pos == 2)
	{
		push_b(lista, listb, lista_init);
		*listb = swap_b(*listb);
	}
	else
		push_b(lista, listb, lista_init);
}

//Code supplementaire pour raccourcir les main_code
int	push_back(t_list2 **lista, t_list2 **listb, int len)
{
	*listb = replace_order(*listb);
	if (len > 1)
		back_bisa(lista, listb);
	len --;
	return (len);
}

int	loop_code(t_list2 **lista, t_list2 **listb, int len_init, int div)
{
	int	count;

	count = 0;
	while (count != len_init / div && *lista)
	{
		if ((*lista)->data > (*lista)->next->data && (*lista)->data
			< (*lista)->next->next->data)
			*lista = swap_a(*lista);
		else if ((*lista)->data < last_list(*lista)->data && *listb
			&& pos_dest(*listb, (*lista)->data))
			*lista = rotate_a(*lista);
		else
		{
			where_pos(lista, listb, *lista);
			count ++;
		}
	}
	return (count);
}

// Code principal : 50 a 100
t_list2	*code_sup100(t_list2 *lista, t_list2 *listb)
{
	int	len;
	int	len_init;

	len_init = len_list(lista);
	len = len_list(lista);
	while (len > 0)
	{
		len = len - loop_code(&lista, &listb, len_init, 4);
		len = push_back(&lista, &listb, len);
	}
	while (len_list(listb) != len_init)
		where_pos(&lista, &listb, lista);
	push_back(&lista, &listb, 2);
	return (lista);
}

t_list2	*code_sup500(t_list2 *lista, t_list2 *listb)
{
	int	len;
	int	len_init;

	len_init = len_list(lista);
	len = len_list(lista);
	while (len > 0)
	{
		len = len - loop_code(&lista, &listb, len_init, 11);
		len = push_back(&lista, &listb, len);
	}
	while (len_list(listb) != len_init)
		where_pos(&lista, &listb, lista);
	push_back(&lista, &listb, 2);
	return (lista);
}
