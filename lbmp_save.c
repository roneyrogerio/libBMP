/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 02:18:02 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/20 03:41:26 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

int	lbmp_save(char *path, t_lbmp *lbmp)
{
	int fd;
	int data_size;

	if (lbmp == NULL)
		return (-1);
	fd = open(path, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 755);
	if (fd < 3)
		return (-1);
	if (write(fd, &lbmp->fheader, 14) < 14)
		return (-1);
	if (write(fd, &lbmp->iheader, 40) < 40)
		return (-1);
	data_size = lbmp->fheader.size - lbmp->fheader.offset;
	if (write(fd, &lbmp->data, data_size) < data_size)
		return (-1);
	return (0);
}
