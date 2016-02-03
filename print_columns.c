/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 01:30:53 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/03 01:31:03 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		print_space(char *str, int len_max)
{
	int	space;

	space = (len_max - ft_strlen(str) + 1);
	while (space-- > 0)
		ft_putchar(' ');
}

void		print_columns(t_data *data, int i, int i_2, int len_max)
{
	int		column;

	column = 0;
	while (i != data->max_row)
	{
		if (data->pos[column][i] == 666)
			ft_putstr("\e[4;36m");
		ft_putstr(data->column[column][i]);
		if (data->pos[column][i] == 666)
			ft_putstr(COLOR_CYAN);
		print_space(data->column[column][i], len_max);
		if (!column)
			column++;
		while (data->column[column])
		{
			if (data->pos[column][i] == 666)
				ft_putstr("\e[4;36m");
			ft_putstr(data->column[column][i]);
			if (data->pos[column][i] == 666)
				ft_putstr(COLOR_CYAN);
			print_space(data->column[column][i], len_max);
			column++;
		}
		column = 0;
		ft_putstr("\n");
		i++;
		i_2++;
	}
}
