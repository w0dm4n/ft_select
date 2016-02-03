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
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>
# define COLUMNS_MAX_SIZE 256

typedef struct	s_data
{
	char	***column;
	int		max_row;
}				t_data;
void		check_size(char **argv, struct winsize size);
t_data		*alloc_memory(t_data *data, struct winsize size);
char		***set_as_null(char ***array);
void		print_columns(t_data *data, int i, int i_2, int len_max);
int			check_argv_rows(char **argv, int max_size);
#endif
