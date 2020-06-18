/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:03:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 02:53:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

t_lbmp	*lbmp_load(char *pathname)
{
	int		fd;
	t_lbmp	*lbmp;

	lbmp = (t_lbmp *)malloc(sizeof(t_lbmp));
	if (lbmp == NULL)
		return (NULL);
	if ((fd = open(pathname, O_RDONLY)) == -1 && lbmp_destroy(lbmp))
		return (NULL);
	if (lbmp_int_load_fheader(&lbmp->fheader, fd) != 0 && lbmp_destroy(lbmp))
		return (NULL);
	if (lbmp_int_load_iheader(&lbmp->iheader, fd) != 0 && lbmp_destroy(lbmp))
		return (NULL);
	return (lbmp);
}

int		lbmp_int_load_fheader(t_lbmp_file_header *fheader, int fd)
{
	int ret;

	ret = lbmp_int_read_16(fd, &fheader->type, 1);
	if (ret == -1 || fheader->type != 0x424d)
		return (-1);
	if (lbmp_int_read_32(fd, &fheader->size, 0) == -1)
		return (-1);
	if (lbmp_int_read_16(fd, &fheader->reserved1, 0) == -1)
		return (-1);
	if (lbmp_int_read_16(fd, &fheader->reserved2, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &fheader->offset, 0) == -1)
		return (-1);
	return (0);
}

int		lbmp_int_load_iheader(t_lbmp_info_header *iheader, int fd)
{
	if (lbmp_int_read_32(fd, &iheader->info_size, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->width, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->height, 0) == -1)
		return (-1);
	if (lbmp_int_read_16(fd, &iheader->planes, 0) == -1)
		return (-1);
	if (lbmp_int_read_16(fd, &iheader->bpp, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->compression, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->img_size, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->x_pels_per_meter, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->y_pels_per_meter, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->clr_used, 0) == -1)
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->clr_important, 0) == -1)
		return (-1);
	return (0);
}
