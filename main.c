/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 00:02:00 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/02 00:02:17 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		main(int argc, char **argv, char **env)
{
	struct winsize	s;
	t_data			*data;

	env = NULL;
	if (argc == 1)
		return (0);
	else
	{
		while (1)
		{
			sig_handler();
			if (g_resize_window == 1)
			{
				ft_putstr("RESIZE");
				g_resize_window = 0;
			}
			ft_putstr(COLOR_CYAN);
			ft_putstr(HIDE_CURSOR);
			ioctl(0, TIOCGWINSZ, &s);
			data = check_size(argv, s);
			read_all_char(argv, data, s);
		}
	}
	return (0);
}
