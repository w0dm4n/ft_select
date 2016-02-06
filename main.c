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
		sig_handler();
		ft_putstr(COLOR_CYAN);
		ft_putstr(HIDE_CURSOR);
		ioctl(0, TIOCGWINSZ, &s);
		data = check_size(argv, s);
		g_argv = argv;
		read_all_char(argv, data, s);
	}
	return (0);
}
