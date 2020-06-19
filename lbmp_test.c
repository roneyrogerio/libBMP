/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:08:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/19 19:22:30 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp.h"
#include <stdio.h>
#include <mlx.h>

int		main(void)
{
	void		*lbmp;
	int			width;
	int			height;
	int			bpp;
	uint32_t	pxl;
	void		*pxl_ptr;
	int			x;
	int			y;
	void		*mlx;
	void		*win;

	lbmp = lbmp_load("file.bmp");
	if (lbmp == NULL)
		printf("error\n");
	else
	{
		mlx = mlx_init();
		width = lbmp_get_width(lbmp);
		height = lbmp_get_height(lbmp);
		win = mlx_new_window(mlx, width, height, "BMP File");
		bpp = lbmp_get_bpp(lbmp);
		
		y = 0;
		while (y < height)
		{
			x = 0;
			while (x < width)
			{
				pxl_ptr = lbmp_get_pixel_ptr(x, y, lbmp);
				pxl = lbmp_get_pixel_color(pxl_ptr, bpp);
				mlx_pixel_put (mlx, win, x, y, pxl);
				x++;
			}
			y++;
		}
		mlx_loop(mlx);
	}
	lbmp_destroy(lbmp);
}
