#include "all.h"

static int		**change_value_cursor(int **pos_tmp, int i, int i_2, int size)
{
	if ((i_2 + 3) == size)
	{
		pos_tmp[i][i_2] = 1;
		if (pos_tmp[i + 1][0] == SELECTED_ONLY)
			pos_tmp[i + 1][0] = CURSOR_N_SELECTED;
		else
			pos_tmp[i + 1][0] = CURSOR_ONLY;
	}
	else
	{
		pos_tmp[i][i_2] = 1;
		if (pos_tmp[i][i_2 + 1] == SELECTED_ONLY)
			pos_tmp[i][i_2 + 1] = CURSOR_N_SELECTED;
		else
			pos_tmp[i][i_2 + 1] = CURSOR_ONLY;
	}
	return (pos_tmp);
}

static int		**change_value_selected_n_cursor(int **pos_tmp, int i, int i_2, int size)
{
	if ((i_2 + 3) == size)
	{
		pos_tmp[i][i_2] = SELECTED_ONLY;
		if (pos_tmp[i + 1][0] == SELECTED_ONLY)
			pos_tmp[i + 1][0] = CURSOR_N_SELECTED;
		else
			pos_tmp[i + 1][0] = CURSOR_ONLY;
	}
	else
	{
		pos_tmp[i][i_2] = SELECTED_ONLY;
		if (pos_tmp[i][i_2 + 1] == SELECTED_ONLY)
			pos_tmp[i][i_2 + 1] = CURSOR_N_SELECTED;
		else
			pos_tmp[i][i_2 + 1] = CURSOR_ONLY;
	}
	return (pos_tmp);
}

int				**go_down(int **pos_tmp, struct winsize s, int i, t_data *data)
{
	int i_2;

	i_2 = 0;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == CURSOR_ONLY)
			{
				if (i == data->size)
					if (!data->column[i][i_2 + 1])
						break ;
				pos_tmp = change_value_cursor(pos_tmp, i, i_2, s.ws_row);
				break ;
			}
			else if (pos_tmp[i][i_2] == CURSOR_N_SELECTED)
			{
				if (i == data->size)
					if (!data->column[i][i_2 + 1])
						break ;
				pos_tmp = change_value_selected_n_cursor(pos_tmp, i, i_2, s.ws_row);
				break ;
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}
