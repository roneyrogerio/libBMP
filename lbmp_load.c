/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:03:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 01:06:32 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"
#include <stdio.h>
#include <byteswap.h>

void	lbmp_destroy(t_lbmp *lbmp)
{
	free(lbmp);
}

t_lbmp	*lbmp_load(char *pathname)
{
	int		fd;
	t_lbmp	*lbmp;

	lbmp = (t_lbmp *)malloc(sizeof(t_lbmp));
	if (lbmp == NULL)
		return (NULL);
	if ((fd = open(pathname, O_RDONLY)) == -1)
	{
		lbmp_destroy(lbmp);
		return (NULL);
	}
	if (lbmp_int_load_fheader(&lbmp->fheader, fd) != 0)
	{
		lbmp_destroy(lbmp);
		return (NULL);
	}
	return (lbmp);
}

int		lbmp_int_load_fheader(t_lbmp_file_header *fheader, int fd)
{
	int	ret;

	ret = lbmp_int_read_16(fd, &fheader->type, 1);
	if (ret == -1 || fheader->type != 0x424d)
		return (1);
	if ((ret = lbmp_int_read_32(fd, &fheader->size, 0)) == -1)
		return (1);
	if ((ret = lbmp_int_read_16(fd, &fheader->reserved1, 0)) == -1)
		return (1);
	if ((ret = lbmp_int_read_16(fd, &fheader->reserved2, 0)) == -1)
		return (1);
	if ((ret = lbmp_int_read_32(fd, &fheader->offset, 0)) == -1)
		return (1);
	return (0);
}
