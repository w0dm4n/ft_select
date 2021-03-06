/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 22:47:10 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/02 22:47:14 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_data		*get_column(t_data *data, char **argv, int max_row)
{
	int	i;
	int i_2;
	int column;

	i = 1;
	i_2 = 0;
	column = 0;
	while (argv[i])
	{
		if (i_2 >= max_row)
		{
			column++;
			i_2 = 0;
		}
		if (ft_strcmp(argv[i], "deleted"))
		{
			data->column[column][i_2] = ft_strdup(argv[i]);
			i_2++;
		}
		i++;
	}
	data->column[column + 1] = NULL;
	data->size = column;
	exit_if_empty(i_2);
	return (data);
}

int			get_bigger(t_data *data)
{
	int		column;
	int		i;
	size_t	tmp_size;

	column = 0;
	i = 0;
	tmp_size = 0;
	while (data->column[column])
	{
		while (data->column[column][i])
		{
			if (tmp_size < ft_strlen(data->column[column][i]))
				tmp_size = ft_strlen(data->column[column][i]);
			i++;
		}
		i = 0;
		column++;
	}
	return (tmp_size);
}

int			check_column_size(t_data *data, int max_column)
{
	int		column;
	int		i;
	size_t	tmp_size;
	int		size;

	column = 0;
	i = 0;
	tmp_size = 0;
	size = 0;
	while (data->column[column])
	{
		while (data->column[column][i])
		{
			if (tmp_size < ft_strlen(data->column[column][i]))
				tmp_size = ft_strlen(data->column[column][i]);
			i++;
		}
		size += (tmp_size + 3);
		tmp_size = 0;
		i = 0;
		column++;
	}
	return ((size <= max_column) ? 1 : 0);
}

t_data		*check_size_col(struct winsize size, char **argv)
{
	t_data	*data;
	int		i;
	int		i_2;
	int		column;

	i = 0;
	i_2 = 0;
	column = 0;
	data = NULL;
	if (!(data = alloc_memory(data, size)))
		return (NULL);
	data = get_column(data, argv, (size.ws_row - 2));
	if (check_column_size(data, size.ws_col))
		return (data);
	else
	{
		ft_putstr("Windows size is too small !\n");
		read_all_char(argv, data, size);
	}
	return (NULL);
}

t_data		*check_size(char **argv, struct winsize size)
{
	t_data	*data;

	if ((data = check_size_col(size, argv)) != NULL)
		print_columns(data, 0, 0, get_bigger(data));
	return (data);
}
