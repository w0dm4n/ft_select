/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 02:11:16 by frmarinh          #+#    #+#             */
/*   Updated: 2016/02/06 02:12:18 by frmarinh         ###   ########.fr       */
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
