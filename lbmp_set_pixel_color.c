/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_set_pixel_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 22:38:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/19 23:59:06 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

/*
**I can use memcpy!
*/

int	lbmp_set_pixel_color(void *ptr, uint32_t new, int bpp)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (-1);
	bpp /= 8;
	new_ptr = &new;
	while (bpp--)
		*(unsigned char *)ptr++ = *(unsigned char *)new_ptr++;
	return (0);
}
