/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_get_pixel_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:05:22 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/20 00:07:45 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

void	*lbmp_get_pixel_ptr(int x, int y, t_lbmp *lbmp)
{
	int	offset;
	int	stride;
	int width;
	int height;
	int bpp;

	if (lbmp == NULL || lbmp->data == NULL)
		return (NULL);
	height = lbmp->iheader.height;
	width = lbmp->iheader.width;
	bpp = lbmp->iheader.bpp;
	stride = ((((width * bpp) + 31) & ~31) >> 3);
	offset = ((height - y - 1) * stride + x * (bpp / 8));
	return (lbmp->data + offset);
}
