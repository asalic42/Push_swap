/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:55:13 by asalic            #+#    #+#             */
/*   Updated: 2023/04/17 11:55:56 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Who is the smallest ?
int	smallest(t_list2 *list)
{
	int	small;

	small = list->data;
	list = list->next;
	while (list)
	{
		if (small > list->data)
			small = list->data;
		list = list->next;
	}
	return (small);
}

// Who is the biggest ?
int	biggest(t_list2 *list)
{
	int	big;

	big = list->data;
	list = list->next;
	while (list)
	{
		if (big < list->data)
			big = list->data;
		list = list->next;
	}
	return (big);
}
