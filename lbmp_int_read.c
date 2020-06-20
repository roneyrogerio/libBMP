/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_int_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:57:25 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/20 00:01:40 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

int	lbmp_int_read_16(int fd, uint16_t *buffer)
{
	int			ret;

	if (fd < 1 || buffer == NULL)
		return (-1);
	ret = read(fd, (void *)buffer, 2);
	if (ret != 2)
		return (-1);
	return (0);
}

int	lbmp_int_read_32(int fd, uint32_t *buffer)
{
	int			ret;

	if (fd < 1 || buffer == NULL)
		return (-1);
	ret = read(fd, (void *)buffer, 4);
	if (ret != 4)
		return (-1);
	return (0);
}
