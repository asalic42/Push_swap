/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:43:45 by asalic            #+#    #+#             */
/*   Updated: 2023/02/08 11:36:21 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_to(char *str, int c)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != c)
		len ++;
	return (len);
}

char	*go_malloc(size_t size)
{
	size_t	i;
	char	*tab;

	tab = malloc((size + 1) * sizeof(char));
	if (!tab)
		return (free(tab), NULL);
	i = 0;
	while (i < size)
		tab[i++] = '\0';
	tab[i] = '\0';
	return (tab);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1)
		s1 = go_malloc(1);
	tab = go_malloc(count_to(s1, '\0') + count_to(s2, '\0'));
	if (!tab)
		return (free(tab), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i ++;
	}
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free (s1);
	free (s2);
	return (tab);
}

char	*dup_to_n(char *str, int c)
{
	char	*dup;
	int		i;

	if (!str)
		return (NULL);
	if (count_to(str, '\0'))
	{
		dup = go_malloc(count_to(str, '\0'));
		if (!dup)
			return (free(dup), NULL);
	}
	else
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dup[i] = str[i];
		i ++;
	}
	if (str[i] == '\n' && c == '\n')
		dup[i ++] = '\n';
	dup[i] = '\0';
	return (dup);
}

char	*find_n(char *str)
{
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i ++;
			temp = dup_to_n(str + i, '\0');
			return (temp);
		}
		i ++;
	}
	return (NULL);
}
