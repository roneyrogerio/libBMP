/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_get_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 02:05:22 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/20 00:08:41 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

int	lbmp_get_pixel_color(void *ptr, int bpp)
{
	uint32_t	n;

	if (ptr == NULL)
		return (0);
	n = *(uint32_t *)ptr;
	if (bpp == 32)
		return (n);
	return (n & ~(~0 << bpp));
}
