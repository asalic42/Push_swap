/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:10:41 by asalic            #+#    #+#             */
/*   Updated: 2023/04/13 12:05:55 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*gerer les cas d'erreurs : - pas d'autres caracteres que des int
							- pas de doublons
                            - pas de int > int_max ou int < int_min */

#include "push_swap.h"

t_bool	compare(char **tab, int nb, int pos)
{
	int	tmp;

	pos ++;
	while (tab[pos])
	{
		tmp = ft_atoi(tab[pos]);
		if (nb == tmp)
			return (true);
		pos ++;
	}
	return (false);
}

t_bool	char_compare(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (s1[i] && s1[i] == s2[i])
	{
		if (i == ft_strlen(s1) - 1)
			return (true);
		i ++;
	}
	return (false);
}

t_bool	is_toolong(char *tab)
{
	int		i;
	int		len;
	int		nbr;
	char	*nbr_char;

	len = ft_strlen(tab);
	i = 0;
	if (len >= 12)
		return (false);
	if (len == 11 && tab[i] != '-')
		return (false);
	nbr = ft_atoi(tab);
	nbr_char = ft_itoa(nbr);
	if (!(char_compare(tab, nbr_char)))
	{
		free(nbr_char);
		return (false);
	}
	free(nbr_char);
	return (true);
}

t_bool	check_errors(int len, char **tab)
{
	int	i;

	i = 1;
	while (i != len)
	{
		if (!(is_toolong(tab[i])))
		{
			ft_printf("Error\n");
			return (false);
		}
		if (compare(tab, ft_atoi(tab[i]), i))
		{
			ft_printf("Error\n");
			return (false);
		}
		i ++;
	}
	return (true);
}
