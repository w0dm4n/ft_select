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
	if (signo == SIGWINCH)
		g_resize_window = 1;
}

void		sig_handler(void)
{
	signal(SIGINT, exit_program);
	signal(SIGWINCH, re_size_column);
}