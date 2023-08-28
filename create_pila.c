/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pila.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:46:08 by asalic            #+#    #+#             */
/*   Updated: 2023/04/12 19:42:22 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// creer la pile a avec les arguments passes en parametre a l'aide des listes
t_cell	*create_cell(int data)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

t_list2	*free_list(t_list2 *list, int free2)
{
	t_list2	*tmp;

	tmp = list;
	if (free2 == 0)
	{
		tmp = list->next;
		free(list);
		return (tmp);
	}
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free (tmp);
	return (list);
}

t_list2	*pile_a(int data, t_list2 *list)
{
	t_cell	*cell;

	cell = create_cell(data);
	if (!list)
		list = cell;
	else
	{
		cell->next = list;
		list = cell;
	}
	return (list);
}

t_list2	*create_pile(int len, char **tab)
{
	t_list2	*list;
	int		i;

	i = len -1;
	list = NULL;
	while (i != 0)
	{
		list = pile_a(ft_atoi(tab[i]), list);
		i --;
	}
	return (list);
}

void	print_list(t_list2 *list)
{
	while (list)
	{
		ft_printf("%d ", list->data);
		list = list->next;
	}
}
