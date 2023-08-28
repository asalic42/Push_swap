/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:26:09 by asalic            #+#    #+#             */
/*   Updated: 2023/04/13 11:09:24 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction qui va dire si le nb est bien le + proche de small
// dans la liste donnee
t_bool	is_closer(t_list2 *list, int small, int nb)
{
	while (list && list->next)
	{
		if (list->data == small || list->data == nb)
			list = list->next;
		else if (list->data > small && list->data < nb)
			return (false);
		else
			list = list->next;
	}
	return (true);
}

//Fonction qui cherche la future position triee du nombre
int	pos_dest(t_list2 *list, int nb)
{
	t_list2	*last;
	int		pos;

	pos = 1;
	if (list)
	{
		last = last_list(list);
		while (list->next)
		{
			if (nb > biggest(list) && list->data == biggest(list))
				return (pos);
			else if (pos == 1 && nb < smallest(list) && list->data
				== biggest(list))
				return (0);
			else if ((nb < smallest(list) && list->data == smallest(list))
				|| (nb < list->data && nb > list->next->data))
				return (++pos);
			else if (pos == 1 && nb > list->data && nb < last->data)
				return (pos);
			pos ++;
			list = list->next;
		}
	}
	return (pos);
}

// Fonction qui va remettre le nombre le + grand de la pile triee en haut
t_list2	*replace_order(t_list2 *listb)
{
	int	big_count;
	int	lenb;
	int	i;

	i = 0;
	big_count = counter(listb, biggest(listb));
	lenb = len_list(listb);
	if (big_count > lenb / 2)
	{
		while (i < (lenb - big_count))
		{
			listb = reverse_rotate_b(listb);
			i ++;
		}
	}
	else
	{
		while (i <= big_count -1)
		{
			listb = rotate_b(listb);
			i ++;
		}
	}
	return (listb);
}

// Fonction qui va rotate ou reverse_rotate la PileB en fonction du
// placement du nombre
t_list2	*rotate_pileb(t_list2 *listb, int pos)
{
	int	lenb;
	int	i;

	i = 1;
	lenb = len_list(listb);
	if (pos > lenb / 2)
	{
		while (i <= (lenb - pos) + 1)
		{
			listb = reverse_rotate_b(listb);
			i ++;
		}
	}
	else
	{
		while (i <= pos -1)
		{
			listb = rotate_b(listb);
			i ++;
		}
	}
	return (listb);
}

// Meme fonctionnement que back_inA mais pour + de nombres
void	back_bisa(t_list2 **lista, t_list2 **listb)
{
	int	lenb;

	lenb = len_list(*listb);
	if (*lista == NULL)
	{
		while (lenb != 0)
		{
			push_a(lista, listb, *listb);
			lenb --;
		}
	}
	else
	{
		while (lenb != 0)
		{
			push_a(lista, listb, *listb);
			*lista = rotate_a(*lista);
			lenb --;
		}
	}
}
