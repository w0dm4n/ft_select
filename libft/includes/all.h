/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 00:03:22 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/02 00:04:14 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <unistd.h>
# include "libft.h"
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>
# define COLUMNS_MAX_SIZE 256
# define DEFAULT_COLOR "\e[1;37m"
# define COLOR_BLUE "\e[0;34m"
# define COLOR_PURPLE "\e[0;35m"
# define COLOR_YELLOW "\e[1;33m"
# define COLOR_GREEN "\e[0;32m"
# define COLOR_CYAN "\e[0;36m"
# define COLOR_RED "\e[0;31m"
# define COLOR_LIGHT_RED "\e[1;31m"
# define MOVE_UP_LEFT "\033[H"
# define CLEAR_SCREEN "\033[2J"
# define HIDE_CURSOR "\033[?25l"
# define SHOW_CURSOR "\033[?25h"
# define ARROW_UP 183
# define ARROW_DOWN 184
# define ARROW_LEFT 186
# define ARROW_RIGHT 185

typedef struct	s_data
{
	char	***column;
	int		**pos;
	int		max_row;
	int		size;
}				t_data;
t_data		*check_size(char **argv, struct winsize size);
t_data		*alloc_memory(t_data *data, struct winsize size);
char		***set_as_null(char ***array);
void		print_columns(t_data *data, int i, int i_2, int len_max);
int			check_argv_rows(char **argv, int max_size);
int			get_bigger(t_data *data);
int			check_column_size(t_data *data, int max_column);
t_data		*get_column(t_data *data, char **argv, int max_row);
int			**go_down(int **pos_tmp, struct winsize s, int i, int i_2);
#endif
