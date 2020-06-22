/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_get_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:05:22 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/21 21:41:54 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

int	lbmp_get_pixel_color(t_lbmp *lbmp, int x, int y)
{
	uint32_t	n;

	if (lbmp == NULL)
		return (0);
	n = *(uint32_t *)lbmp_int_get_pixel_ptr(lbmp, x, y);
	return (n & ~(~0 << lbmp->iheader.bpp));
}
