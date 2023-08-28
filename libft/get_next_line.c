/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:43:40 by asalic            #+#    #+#             */
/*   Updated: 2023/02/08 11:36:48 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*final_return(char	*temp)
{
	char	*str_final;

	if (!temp)
		return (NULL);
	str_final = dup_to_n(temp, '\n');
	return (str_final);
}

char	*stockage(char *temp)
{
	char	*var_stock;

	var_stock = find_n(temp);
	if (var_stock)
	{
		free(temp);
		temp = dup_to_n(var_stock, '\0');
		free(var_stock);
		return (temp);
	}
	free (var_stock);
	free (temp);
	return (NULL);
}

char	*add_to_temp(int fd, char *temp)
{
	char	*tab_temp;
	char	*buf;

	buf = go_malloc(BUFFER_SIZE);
	tab_temp = find_n(temp);
	if (!tab_temp)
	{
		while (!tab_temp && read(fd, buf, BUFFER_SIZE) > 0)
		{
			free (tab_temp);
			tab_temp = dup_to_n(temp, '\0');
			free(temp);
			temp = ft_join(tab_temp, buf);
			tab_temp = find_n(temp);
			buf = go_malloc(BUFFER_SIZE);
		}
	}
	free(tab_temp);
	free (buf);
	return (temp);
}

char	*buf_to_temp(int fd, char *temp)
{
	char	*buf;
	char	*tab_temp;

	buf = go_malloc(BUFFER_SIZE);
	if (read(fd, buf, BUFFER_SIZE))
	{
		if (temp)
		{
			tab_temp = dup_to_n(temp, '\0');
			free(temp);
			temp = ft_join(tab_temp, buf);
		}
		else
		{
			temp = dup_to_n(buf, '\0');
			free (buf);
		}
		tab_temp = dup_to_n(temp, '\0');
		free (temp);
		temp = add_to_temp(fd, tab_temp);
	}
	else
		free (buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*final;
	static char		*temp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	temp = buf_to_temp(fd, temp);
	final = final_return(temp);
	temp = stockage(temp);
	return (final);
}
