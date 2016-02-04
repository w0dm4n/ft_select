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

int		**set_selected(int **pos_tmp, struct winsize s, int i, int i_2)
{
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (pos_tmp[i][i_2] == 666)
			{
				pos_tmp[i][i_2] = 999;
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