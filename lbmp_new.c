/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 00:37:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/02 06:16:35 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

/*
** i can use calloc! **
*/

void	*lbmp_new(int width, int height, int bpp)
{
	t_lbmp	*lbmp;
	int		data_size;

	if (bpp != 24 && bpp != 32)
		return (lbmp_int_set_err(LBMP_BPPERR));
	lbmp = (t_lbmp *)malloc(sizeof(t_lbmp));
	if (lbmp == NULL)
		return (lbmp_int_set_err(LBMP_MEMERR));
	data_size = width * height * (bpp / 8);
	if ((lbmp->data = malloc(data_size)) == NULL && lbmp_destroy(lbmp))
		return (lbmp_int_set_err(LBMP_MEMERR));
	lbmp_int_bzero(lbmp);
	lbmp->fheader.type = 0x4d42;
	lbmp->fheader.size = 54 + data_size;
	lbmp->fheader.offset = 54;
	lbmp->iheader.info_size = 40;
	lbmp->iheader.width = width;
	lbmp->iheader.height = height;
	lbmp->iheader.bpp = bpp;
	lbmp->iheader.img_size = data_size;
	return (lbmp);
}

void	lbmp_int_bzero(t_lbmp *lbmp)
{
	lbmp->fheader.reserved1 = 0;
	lbmp->fheader.reserved2 = 0;
	lbmp->iheader.planes = 0;
	lbmp->iheader.compression = 0;
	lbmp->iheader.x_pels_per_meter = 0;
	lbmp->iheader.y_pels_per_meter = 0;
	lbmp->iheader.clr_used = 0;
	lbmp->iheader.clr_important = 0;
}
