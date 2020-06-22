/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:08:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/22 01:54:05 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp.h"
#include <unistd.h>

int		main(void)
{
	void		*lbmp;
	int			x;
	int			y;

	lbmp = lbmp_load("file.bmp");
	if (lbmp == NULL)
		write(2, "error\n", 6);
	else
	{
		y = 75;
		x = 0;
		while (y < 100)
		{
			lbmp_set_pixel_color(lbmp, x, y, 0xFF0000);
			x++;
			if (x == 500)
			{
				x = 0;
				y++;
			}
		}
		lbmp_save("altered-file.bmp", lbmp);
		write(1, "The altered image is saved as altered-file.bmp\n", 47);
	}
	lbmp_destroy(lbmp);
}
