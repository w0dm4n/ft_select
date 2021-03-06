/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 05:37:42 by frmarinh          #+#    #+#             */
/*   Updated: 2016/01/07 05:38:18 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_fd(int *array, int const fd)
{
	int i;

	i = 1;
	while (array[i])
	{
		if (array[i] == fd)
			return (i);
		i++;
	}
	return (0);
}
