/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 02:56:50 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/04 02:56:57 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

int		**handle_positions(int **pos, char *b, t_data *data, struct winsize s)
{
	if (get_ascii_value(b) == ARROW_DOWN)
		pos = go_down(pos, s, -1, data);
	if (get_ascii_value(b) == ARROW_UP)
		pos = go_up(pos, s, 0, 0);
	if (get_ascii_value(b) == ARROW_RIGHT)
		pos = go_right(pos, s, 0, data);
	if (get_ascii_value(b) == ARROW_LEFT)
		pos = go_left(pos, s, 0, 0);
	if (get_ascii_value(b) == SPACE)
		pos = set_selected(pos, s, 0, data);
	return (pos);
}

void	get_return_and_exit(t_data *data, struct winsize s)
{
	int	i;
	int i_2;

	i = 0;
	i_2 = 0;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (data->pos[i][i_2] == SELECTED_ONLY
				|| data->pos[i][i_2] == CURSOR_N_SELECTED)
			{
				ft_putstr(data->column[i][i_2]);
				ft_putstr(" ");
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	ft_putstr(SHOW_CURSOR);
	exit(0);
}

t_data	*update_argv(t_data *data, char **argv, struct winsize s)
{
	int	i;
	int i_2;
	int i_3;
	int column;

	i = 0;
	i_2 = 0;
	i_3 = 0;
	column = 0;
	while (i < COLUMNS_MAX_SIZE)
	{
		while (i_2 < s.ws_row)
		{
			if (data->pos[i][i_2] == CURSOR_ONLY ||
				data->pos[i][i_2] == CURSOR_N_SELECTED)
			{
				while (*argv)
				{
					if (i_2 >= (s.ws_row - 2))
					{
						column++;
						i_3 = 0;
					}
					if (data->pos[column][i_3] == CURSOR_ONLY ||
						data->pos[column][i_3] == CURSOR_N_SELECTED)
					{
						ft_putstr("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
						*argv = ft_strdup("deleted");
						data->pos[i][i_2] = 1;
						data->pos[i][i_2 - 1] = CURSOR_ONLY;
					}
					argv++;
					i_3++;
				}
			}
			i_2++;
		}
		i_2 = 0;
		i++;
	}
	return (data);
}

t_data	*handle_col(t_data *data, struct winsize s, char *buffer, char **argv)
{
	int		**pos_tmp;
	int		size_tmp;

	pos_tmp = data->pos;
	size_tmp = data->size;
	free(data);
	ioctl(0, TIOCGWINSZ, &s);
	if (!(data = alloc_memory(data, s)))
		return (NULL);
	ft_putstr(CLEAR_SCREEN);
	data->size = size_tmp;
	data->pos = pos_tmp;
	if (get_ascii_value(buffer) == DELETE ||
		get_ascii_value(buffer) == BACKSPACE)
		data = update_argv(data, argv, s);
	data = get_column(data, argv, (s.ws_row - 2));
	pos_tmp = handle_positions(pos_tmp, buffer, data, s);
	if (check_column_size(data, s.ws_col))
		print_columns(data, 0, 0, get_bigger(data));
	else
		ft_putstr("Windows size is too small !\n");
	g_argv = argv;
	g_pos = data->pos;
	return (data);
}

void	read_all_char(char **argv, t_data *data, struct winsize s)
{
	struct termios	bjr;
	char			*buffer;

	buffer = ft_strnew(10);
	tcgetattr(0, &bjr);
	bjr.c_lflag &= ~ICANON;
	bjr.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &bjr);
	read(0, buffer, 10);
	if (get_ascii_value(buffer) == ESC)
	{
		ft_putstr(SHOW_CURSOR);
		exit(0);
	}
	if (get_ascii_value(buffer) == RETURN)
		get_return_and_exit(data, s);
	data = handle_col(data, s, buffer, argv);
	read_all_char(argv, data, s);
}
