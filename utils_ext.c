/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 02:11:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/06 02:13:01 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void	exit_if_empty(int value)
{
	if (!value)
	{
		ft_putstr(SHOW_CURSOR);
		ft_putstr(CLEAR_SCREEN);
		exit(0);
	}
}

t_data	*del_arg(char *b, t_data *d, char **argv, struct winsize s)
{
	if (get_ascii_value(b) == DELETE ||
		get_ascii_value(b) == BACKSPACE)
	{
		d = upd_arg(d, argv, s, -1);
		d->pos = go_up(d->pos, s, 0, 0);
		d = get_column(d, argv, (s.ws_row - 2));
	}
	return (d);
}
