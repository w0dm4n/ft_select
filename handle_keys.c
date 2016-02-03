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

int		**go_up(int **pos_tmp, struct winsize s, int i, int i_2)
{
	while (i < 256)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == 666)
			{
				if (i_2 == 0)
				{
					if ((i - 1) >= 0 && (pos_tmp[i][i_2] = 1))
						pos_tmp[i - 1][(s.ws_row - 3)] = 666;
				}
				else if ((pos_tmp[i][i_2] = 1))
					pos_tmp[i][i_2 - 1] = 666;
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
	data = NULL;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == 666)
			{
				if ((i_2 + 3) == s.ws_row)
				{
					pos_tmp[i][i_2] = 1;
					pos_tmp[i + 1][0] = 666;
				}
				else
				{
					pos_tmp[i][i_2] = 1;
					pos_tmp[i][i_2 + 1] = 666;
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