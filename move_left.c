/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 23:09:12 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/05 23:09:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

static int		**change_value_selected_n_cursor(int **pos_tmp, int i, int i_2)
{
	if (i == 0)
		return (pos_tmp);
	if (pos_tmp[i][i_2] == CURSOR_ONLY)
		pos_tmp[i][i_2] = 1;
	else if (pos_tmp[i][i_2] == CURSOR_N_SELECTED)
		pos_tmp[i][i_2] = SELECTED_ONLY;
	if (pos_tmp[i - 1][i_2] == SELECTED_ONLY)
		pos_tmp[i - 1][i_2] = CURSOR_N_SELECTED;
	else
		pos_tmp[i - 1][i_2] = CURSOR_ONLY;
	return (pos_tmp);
}

int				**go_left(int **pos_tmp, struct winsize s, int i, int i_2)
{
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == CURSOR_ONLY ||
				pos_tmp[i][i_2] == CURSOR_N_SELECTED)
			{
				pos_tmp = change_value_selected_n_cursor(pos_tmp, i, i_2);
				break ;
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}
