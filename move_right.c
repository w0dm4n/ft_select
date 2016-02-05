/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 23:10:03 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/05 23:10:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static int		**change_value_s_n_c(int **pos, int i, int i_2, t_data *data)
{
	if (i == data->size)
		return (pos);
	if ((i + 1) == data->size)
		if (!data->column[data->size][i_2])
			return (pos);
	if (pos[i][i_2] == CURSOR_ONLY)
		pos[i][i_2] = 1;
	else if (pos[i][i_2] == CURSOR_N_SELECTED)
		pos[i][i_2] = SELECTED_ONLY;
	if (pos[i + 1][i_2] == SELECTED_ONLY)
		pos[i + 1][i_2] = CURSOR_N_SELECTED;
	else
		pos[i + 1][i_2] = CURSOR_ONLY;
	return (pos);
}

int				**go_right(int **pos_tmp, struct winsize s, int i, t_data *data)
{
	int i_2;

	i_2 = 0;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == CURSOR_ONLY ||
				pos_tmp[i][i_2] == CURSOR_N_SELECTED)
			{
				pos_tmp = change_value_s_n_c(pos_tmp, i, i_2, data);
				break ;
			}
			i_2++;
		}
		if (pos_tmp[i + 1][i_2] == CURSOR_ONLY ||
			pos_tmp[i + 1][i_2] == CURSOR_N_SELECTED)
			break ;
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}
