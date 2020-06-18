/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_int_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:57:25 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 01:05:09 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

int	lbmp_int_read_16(int fd, uint16_t *buffer, int swap)
{
	int			ret;

	ret = read(fd, (void *)buffer, 2);
	if (ret != 2)
		return (-1);
	if (swap)
		*buffer = (*buffer >> 8) | (*buffer << 8);
	return (0);
}

int	lbmp_int_read_32(int fd, uint32_t *buffer, int swap)
{
	int			ret;

	ret = read(fd, (void *)buffer, 4);
	if (ret != 4)
		return (-1);
	if (swap)
		*buffer = ((*buffer) >> 24) |
			(((*buffer) & 0x00FF0000) >> 8) |
			(((*buffer) & 0x0000FF00) << 8) |
			((*buffer) << 24);
	return (0);
}
