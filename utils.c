/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:56:39 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/03 00:56:50 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

char		***set_as_null(char ***array)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			array[i] = NULL;
		i++;
	}
	return (array);
}

t_data		*alloc_memory(t_data *data, struct winsize size)
{
	int	i;

	i = 0;
	if (!(data = malloc(sizeof(t_data))))
		return (NULL);
	if (!(data->column = malloc(sizeof(char***) * COLUMNS_MAX_SIZE)))
		return (NULL);
	data->column = set_as_null(data->column);
	while (i <= COLUMNS_MAX_SIZE)
	{
		if (!(data->column[i] = malloc(sizeof(char*) * (size.ws_row + 64))))
			return (NULL);
		i++;
	}
	data->column[0] = ft_set_null(data->column[0]);
	data->max_row = (size.ws_row - 3);
	if (data->max_row < 0)
		data->max_row = 0;
	return (data);
}

int			check_argv_rows(char **argv, int max_size)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return ((i < max_size) ? 1 : 0);
}
