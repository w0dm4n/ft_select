/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 01:16:21 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/04 01:16:29 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		**set_value(int **pos_tmp, int i, int i_2)
{
	if (pos_tmp[i][i_2 + 1] == SELECTED_ONLY)
		pos_tmp[i][i_2 + 1] = CURSOR_N_SELECTED;
	else
		pos_tmp[i][i_2 + 1] = CURSOR_ONLY;
	return (pos_tmp);
}

int		**if_is_only_cursor(int **pos_tmp, int i, int i_2, t_data *data)
{
	pos_tmp[i][i_2] = SELECTED_ONLY;
	if (data->column[i][i_2 + 1])
		pos_tmp = set_value(pos_tmp, i, i_2);
	else if (i == data->size)
		pos_tmp[i][i_2] = CURSOR_N_SELECTED;
	else if (data->column[i + 1][0])
		pos_tmp[i + 1][0] = CURSOR_ONLY;
	return (pos_tmp);
}

int		**if_is_selected_n_cursor(int **pos_tmp, int i, int i_2, t_data *data)
{
	pos_tmp[i][i_2] = 1;
	if (data->column[i][i_2 + 1])
		pos_tmp = set_value(pos_tmp, i, i_2);
	else if (i == data->size)
		pos_tmp[i][i_2] = CURSOR_ONLY;
	else if (data->column[i + 1][0])
		pos_tmp[i + 1][0] = CURSOR_ONLY;
	return (pos_tmp);
}

int		**set_s(int **pos_tmp, struct winsize s, int i, t_data *data)
{
	int i_2;

	i_2 = 0;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == CURSOR_ONLY)
			{
				pos_tmp = if_is_only_cursor(pos_tmp, i, i_2, data);
				break ;
			}
			else if (pos_tmp[i][i_2] == CURSOR_N_SELECTED)
			{
				pos_tmp = if_is_selected_n_cursor(pos_tmp, i, i_2, data);
				break ;
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}
