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

int		get_ascii_value(char *value)
{
	int	i; 
	int	size;

	i = 0;
	size = 0;
	while (value[i])
	{
		size += value[i];
		i++;
	}
	return (size);
}

void	read_all_char(char **argv, t_data *data, struct winsize s)
{
	struct termios	bjr;
	char			*test;
	int				**pos_tmp;
	int				size_tmp;

	test = ft_strnew(10);
	tcgetattr(0, &bjr);
	bjr.c_lflag &= ~ICANON;
	bjr.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &bjr);
	read(0, test, 10);
	if (get_ascii_value(test) == 27)
		exit(0);
	if (data)
	{
		pos_tmp = data->pos;
		size_tmp = data->size;
		free(data);
		ioctl(0, TIOCGWINSZ, &s);
		if (!(data = alloc_memory(data, s)))
			return ;
		ft_putstr(CLEAR_SCREEN);
		data->size = size_tmp;
		data->pos = pos_tmp;
		data = get_column(data, argv, (s.ws_row - 2));
		if (get_ascii_value(test) == ARROW_DOWN)
			go_down(pos_tmp, s, 0, data);
		if (get_ascii_value(test) == ARROW_UP)
			go_up(pos_tmp, s, 0, 0);
		if (get_ascii_value(test) == ARROW_RIGHT)
			go_right(pos_tmp, s, 0, data);
		if (check_column_size(data, s.ws_col))
			print_columns(data, 0, 0, get_bigger(data));
		else
		{
			ft_putstr("Windows size is too small !\n");
			exit(0);
		}
	}
	read_all_char(argv, data, s);
}

int		main(int argc, char **argv, char **env)
{
	struct winsize	s;
	t_data			*data;

	env = NULL;
	if (argc == 1)
		return (0);
	else
	{
		ft_putstr(COLOR_CYAN);
		ioctl(0, TIOCGWINSZ, &s);
		data = check_size(argv, s);
		read_all_char(argv, data, s);
	}
	return (0);
}
