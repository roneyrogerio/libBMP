/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_set_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 22:38:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/19 23:14:42 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

/*
**I can use memcpy!
*/

int	lbmp_set_pixel_color(void *pxl, uint32_t new, int bpp)
{
	void	*new_ptr;

	if (pxl == NULL)
		return (-1);
	bpp /= 8;
	new_ptr = &new;
	while (bpp--)
		*(unsigned char *)pxl++ = *(unsigned char *)new_ptr++;
	return (0);
}
