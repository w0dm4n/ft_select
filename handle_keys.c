/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:45:13 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/03 23:45:20 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		**go_left(int **pos_tmp, struct winsize s, int i, int i_2)
{
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == 666)
			{
				if (i == 0)
					break ;
				pos_tmp[i][i_2] = 1;
				pos_tmp[i - 1][i_2] = 666;
				break ;
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
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
			if (pos_tmp[i][i_2] == 666)
			{
				if (i == data->size)
					break ;
				if ((i + 1) == data->size)
					if (!data->column[data->size][i_2])
						break ;
				pos_tmp[i][i_2] = 1;
				pos_tmp[i + 1][i_2] = 666;
				break ;
			}
			i_2++;
		}
		if (pos_tmp[i + 1][i_2] == 666)
			break ;
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}

int		**go_up(int **pos_tmp, struct winsize s, int i, int i_2)
{
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == 666 || pos_tmp[i][i_2] == 1000)
			{
				if (i_2 == 0)
				{
					if ((i - 1) >= 0)
					{
						if (pos_tmp[i - 1][i_2] != 999)
						{
							if (pos_tmp[i][i_2] == 666)
								pos_tmp[i][i_2] = 1;
							else
								pos_tmp[i][i_2] = 999;
							if (pos_tmp[i - 1][i_2] == 1000)
								pos_tmp[i - 1][(s.ws_row - 3)] = 999;
							else
								pos_tmp[i - 1][(s.ws_row - 3)] = 666;
						}
						else
						{
							pos_tmp[i][i_2] = 999;
							pos_tmp[i - 1][(s.ws_row - 3)] = 1000;
						}
					}
				}
				else
				{
					if (pos_tmp[i][i_2 - 1] != 999)
					{
						pos_tmp[i][i_2] = 1;
						pos_tmp[i][i_2 - 1] = 666;
					}
					else
					{
						pos_tmp[i][i_2] = 999;
						pos_tmp[i][i_2 - 1] = 1000;
					}
				}
				break ;
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}

int		**go_down(int **pos_tmp, struct winsize s, int i, t_data *data)
{
	int i_2;

	i_2 = 0;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == 666)
			{
				if (i == data->size)
					if (!data->column[i][i_2 + 1])
						break ;
				if ((i_2 + 3) == s.ws_row && (pos_tmp[i][i_2] = 1))
					pos_tmp[i + 1][0] = 666;
				else if ((pos_tmp[i][i_2] = 1))
					pos_tmp[i][i_2 + 1] = 666;
				break ;
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (pos_tmp);
}
