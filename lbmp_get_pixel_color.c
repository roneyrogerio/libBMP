/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_get_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:05:22 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/02 06:25:57 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

uint32_t	lbmp_get_pixel_color(t_lbmp *lbmp, int x, int y)
{
	uint32_t	n;

	if (lbmp == NULL)
		return (0);
	n = *(uint32_t *)lbmp_int_get_pixel_ptr(lbmp, x, y);
	if (lbmp->iheader.bpp == 32)
		return (n);
	return (n & ~(~0 << lbmp->iheader.bpp));
}
