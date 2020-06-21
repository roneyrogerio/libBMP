/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_set_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 22:38:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/21 06:03:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

/*
**I can use memcpy!
*/

int	lbmp_set_pixel_color(t_lbmp *lbmp, int x, int y, uint32_t color)
{
	unsigned char	*pixel_ptr;
	unsigned char	*color_ptr;
	int				bypp;

	if (lbmp == NULL)
		return (-1);
	bypp = lbmp->iheader.bpp / 8;
	pixel_ptr = (unsigned char *)lbmp_int_get_pixel_ptr(lbmp, x, y);
	color_ptr = (unsigned char *)&color;
	while (bypp--)
		*pixel_ptr++ = *color_ptr++;
	return (0);
}
