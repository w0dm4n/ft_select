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

int		**handle_positions(int **pos_tmp, char *buffer, t_data *data, struct winsize s)
{
	if (get_ascii_value(buffer) == ARROW_DOWN)
		pos_tmp = go_down(pos_tmp, s, 0, data);
	if (get_ascii_value(buffer) == ARROW_UP)
		pos_tmp = go_up(pos_tmp, s, 0, 0);
	if (get_ascii_value(buffer) == ARROW_RIGHT)
		pos_tmp = go_right(pos_tmp, s, 0, data);
	if (get_ascii_value(buffer) == ARROW_LEFT)
		pos_tmp = go_left(pos_tmp, s, 0, 0);
	if (get_ascii_value(buffer) == SPACE)
		pos_tmp = set_selected(pos_tmp, s, 0, data);
	return (pos_tmp);
}

t_data	*handle_if_multiple_column(t_data *data, struct winsize s, char *buffer, char **argv)
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
	data = get_column(data, argv, (s.ws_row - 2));
	pos_tmp = handle_positions(pos_tmp, buffer, data, s);
	if (check_column_size(data, s.ws_col))
		print_columns(data, 0, 0, get_bigger(data));
	else
		ft_putstr("Windows size is too small !\n");
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
	if (get_ascii_value(buffer) == 27)
		exit(0);
	if (data->size != 1)
		data = handle_if_multiple_column(data, s, buffer, argv);
	else
		ft_putstr("only one column !");
	read_all_char(argv, data, s);
}