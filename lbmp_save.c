/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 02:18:02 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/22 01:54:57 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

int	lbmp_save(char *path, t_lbmp *lbmp)
{
	int fd;
	int data_size;

	if (lbmp == NULL && lbmp_int_set_err(LBMP_NULLERR))
		return (-1);
	fd = open(path, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 755);
	if (fd < 3 && lbmp_int_set_err(LBMP_OPERR))
		return (-1);
	if (lbmp_int_save_fheader(fd, &lbmp->fheader) &&
			lbmp_int_set_err(LBMP_WFHERR))
		return (-1);
	if (lbmp_int_save_iheader(fd, &lbmp->iheader) &&
			lbmp_int_set_err(LBMP_WIHERR))
		return (-1);
	data_size = lbmp->iheader.width * lbmp->iheader.height * 3;
	if (write(fd, lbmp->data, data_size) < data_size)
		return (-1);
	close(fd);
	return (0);
}

int	lbmp_int_save_fheader(int fd, t_lbmp_file_header *fheader)
{
	if (write(fd, &fheader->type, 2) < 2)
		return (-1);
	if (write(fd, &fheader->size, 4) < 4)
		return (-1);
	if (write(fd, &fheader->reserved1, 2) < 2)
		return (-1);
	if (write(fd, &fheader->reserved2, 2) < 2)
		return (-1);
	if (write(fd, &fheader->offset, 4) < 4)
		return (-1);
	return (0);
}

int	lbmp_int_save_iheader(int fd, t_lbmp_info_header *iheader)
{
	if (write(fd, &iheader->info_size, 4) < 4)
		return (-1);
	if (write(fd, &iheader->width, 4) < 4)
		return (-1);
	if (write(fd, &iheader->height, 4) < 4)
		return (-1);
	if (write(fd, &iheader->planes, 2) < 2)
		return (-1);
	if (write(fd, &iheader->bpp, 2) < 2)
		return (-1);
	if (write(fd, &iheader->compression, 4) < 4)
		return (-1);
	if (write(fd, &iheader->img_size, 4) < 4)
		return (-1);
	if (write(fd, &iheader->x_pels_per_meter, 4) < 4)
		return (-1);
	if (write(fd, &iheader->y_pels_per_meter, 4) < 4)
		return (-1);
	if (write(fd, &iheader->clr_used, 4) < 4)
		return (-1);
	if (write(fd, &iheader->clr_important, 4) < 4)
		return (-1);
	return (0);
}
