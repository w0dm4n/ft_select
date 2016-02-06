/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 23:54:55 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/05 23:55:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

void		exit_program(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr(SHOW_CURSOR);
		exit(0);
	}
}

void		re_size_column(int signo)
{
	struct winsize s;
	t_data	*data;

	data = NULL;
	if (signo == SIGWINCH)
	{
		if (!(data = alloc_memory(data, s)))
			return ;
		ioctl(0, TIOCGWINSZ, &s);
		data = get_column(data, g_argv, (s.ws_row - 2));
		ft_putstr(CLEAR_SCREEN);
		if (check_column_size(data, s.ws_col))
			print_columns(data, 0, 0, get_bigger(data));
		else
			ft_putstr("Windows size is too small !\n");
	}
}

void		sig_handler(void)
{
	signal(SIGINT, exit_program);
	signal(SIGWINCH, re_size_column);
}
