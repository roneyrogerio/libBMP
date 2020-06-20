/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:03:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/19 22:07:25 by rde-oliv         ###   ########.fr       */
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
	if (lbmp_int_load_fheader(&lbmp->fheader, fd) && lbmp_destroy(lbmp))
		return (NULL);
	if (lbmp_int_load_iheader(&lbmp->iheader, fd) && lbmp_destroy(lbmp))
		return (NULL);
	if (lbmp->iheader.compression != 0)
		return (NULL);
	if (lbmp_int_offset(fd, lbmp->fheader.offset - 54) && lbmp_destroy(lbmp))
		return (NULL);
	if (lbmp_int_load_pixels(fd, lbmp) && lbmp_destroy(lbmp))
		return (NULL);
	return (lbmp);
}

int		lbmp_int_load_fheader(t_lbmp_file_header *fheader, int fd)
{
	if (lbmp_int_read_16(fd, &fheader->type))
		return (-1);
	if (fheader->type != 0x4d42)
		return (-1);
	if (lbmp_int_read_32(fd, &fheader->size))
		return (-1);
	if (lbmp_int_read_16(fd, &fheader->reserved1))
		return (-1);
	if (lbmp_int_read_16(fd, &fheader->reserved2))
		return (-1);
	if (lbmp_int_read_32(fd, &fheader->offset))
		return (-1);
	return (0);
}

int		lbmp_int_load_iheader(t_lbmp_info_header *iheader, int fd)
{
	if (lbmp_int_read_32(fd, &iheader->info_size))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->width))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->height))
		return (-1);
	if (lbmp_int_read_16(fd, &iheader->planes))
		return (-1);
	if (lbmp_int_read_16(fd, &iheader->bpp))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->compression))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->img_size))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->x_pels_per_meter))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->y_pels_per_meter))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->clr_used))
		return (-1);
	if (lbmp_int_read_32(fd, &iheader->clr_important))
		return (-1);
	return (0);
}

int		lbmp_int_load_pixels(int fd, t_lbmp *lbmp)
{
	int		size;
	void	*buffer;

	size = lbmp->fheader.size - lbmp->fheader.offset;
	buffer = malloc(size);
	if (!buffer || read(fd, buffer, size) < size)
		return (-1);
	lbmp->data = buffer;
	return (0);
}
