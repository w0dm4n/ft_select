#include "all.h"

static int		**change_value_selected_n_cursor(int **pos_tmp, int i, int i_2, t_data *data)
{
	if (i == data->size)
		return (pos_tmp);
	if ((i + 1) == data->size)
		if (!data->column[data->size][i_2])
				return (pos_tmp);
	if (pos_tmp[i][i_2] == CURSOR_ONLY)
		pos_tmp[i][i_2] = 1;
	else if (pos_tmp[i][i_2] == CURSOR_N_SELECTED)
		pos_tmp[i][i_2] = SELECTED_ONLY;
	if (pos_tmp[i + 1][i_2] == SELECTED_ONLY)
		pos_tmp[i + 1][i_2] = CURSOR_N_SELECTED;
	else
		pos_tmp[i + 1][i_2] = CURSOR_ONLY;
	return (pos_tmp);
}

int		**go_right(int **pos_tmp, struct winsize s, int i, t_data *data)
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
				pos_tmp = change_value_selected_n_cursor(pos_tmp, i, i_2, data);
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