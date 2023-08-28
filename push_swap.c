/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:31:15 by asalic            #+#    #+#             */
/*   Updated: 2023/04/17 11:50:15 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_range(t_list2 *lista)
{
	int	len;

	len = len_list(lista);
	while (len != 0 && lista->next)
	{
		if (lista->data > lista->next->data)
			return (false);
		if (!is_closer(lista, lista->data, lista->next->data))
			return (false);
		lista = lista->next;
		len --;
	}
	return (true);
}

t_list2	*cloud_pile(t_list2 *pile_a, t_list2 *pile_b, int argc)
{
	if (argc == 3)
		pile_a = check_algo2(pile_a);
	if (argc == 4)
		pile_a = check_algo3(pile_a);
	if (argc >= 5 && argc <= 50)
		pile_a = main_code(pile_a, pile_b);
	if (argc >= 51 && argc <= 101)
		pile_a = code_sup100(pile_a, pile_b);
	if (argc >= 102)
		pile_a = code_sup500(pile_a, pile_b);
	return (pile_a);
}

int	main(int argc, char **argv)
{
	t_list2	*pile_a;
	t_list2	*pile_b;

	pile_b = NULL;
	pile_a = NULL;
	if (argc < 2)
		return (0);
	if (!(check_errors(argc, argv)))
		return (0);
	pile_a = create_pile(argc, argv);
	if (!is_range(pile_a))
		pile_a = cloud_pile(pile_a, pile_b, argc);
	pile_a = free_list(pile_a, 1);
	return (0);
}
