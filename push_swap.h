/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:54:11 by asalic            #+#    #+#             */
/*   Updated: 2023/04/12 17:21:48 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/libftprintf/libftprintf.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct Liste
{
	int				data;
	struct Liste	*next;
}t_list2,	t_cell;

typedef enum Booleen
{
	false,
	true
}t_bool;

//Pile A creation
t_list2	*pile_a(int data, t_list2 *list);
t_list2	*free_list(t_list2 *list, int free2);
t_list2	*create_cell(int data);
t_list2	*create_pile(int len, char **tab);
t_list2	*cloud_pile(t_list2 *pile_a, t_list2 *pile_b, int argc);

//Aides fonctions listes
t_list2	*delback(t_list2 *lst);
t_list2	*last_list(t_list2 *list);
void	print_list(t_list2 *list);
void	addfront_list(t_list2 **lst, int data);
int		len_list(t_list2 *list);
int		last_init(t_list2 *list);

//Cas d'erreurs
t_bool	check_errors(int len, char **tab);
t_bool	compare(char **tab, int nb, int pos);
t_bool	char_compare(char *s1, char *s2);
t_bool	is_toolong(char *tab);

//Operations
t_list2	*swap_a(t_list2 *list);
t_list2	*swap_b(t_list2 *list);
t_list2	*rotate_a(t_list2 *lista);
t_list2	*rotate_b(t_list2 *listb);
t_list2	*reverse_rotate_a(t_list2 *lista);
t_list2	*reverse_rotate_b(t_list2 *listb);
void	reverse_rotate_ab(t_list2 **lista, t_list2 **listb);
void	swap_ab(t_list2 **lista, t_list2 **listb);
void	push_a(t_list2 **lista, t_list2 **listb, t_list2 *listb_init);
void	push_b(t_list2	**lista, t_list2 **listb, t_list2 *lista_init);
void	rotate_ab(t_list2 **lista, t_list2 **listb);

//Mini Algo
t_list2	*first_pos(t_list2 *lista);
t_list2	*reverse_order(t_list2 *lista);
t_list2	*check_algo2(t_list2 *lista);
t_list2	*check_algo3(t_list2 *lista);

//Algo Test 1
int		biggest(t_list2 *list);
int		smallest(t_list2 *list);
t_bool	is_rangea(t_list2 *lista, t_list2 *listb);
void	back_ina(t_list2 **lista, t_list2 **listb, t_list2 *lista_init);
t_list2	*main_code(t_list2 *lista, t_list2 *listb);

//Algo tri 100 et 500 par insertion opti
t_list2	*code_sup100(t_list2 *lista, t_list2 *listb);
t_list2	*code_sup500(t_list2 *lista, t_list2 *listb);
int		push_back(t_list2 **lista, t_list2 **listb, int len);
void	where_pos(t_list2 **lista, t_list2 **listb, t_list2 *lista_init);
void	back_bisa(t_list2 **lista, t_list2 **listb);

//Utils
t_bool	is_closer(t_list2 *list, int small, int nb);
t_list2	*rotate_pileb(t_list2 *listb, int pos);
t_list2	*replace_order(t_list2 *listb);
int		pos_dest(t_list2 *list, int nb);
int		counter(t_list2 *list, int nb);

#endif
