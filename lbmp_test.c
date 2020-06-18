/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:08:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 04:02:03 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp.h"
#include <stdio.h>

int		main(void)
{
	void	*lbmp;

	lbmp = lbmp_load("test.bmp");
	if (lbmp == NULL)
		printf("error");
	else
	{
		printf("image size : %u\n", lbmp_get_size(lbmp));
		printf("width      : %u\n", lbmp_get_width(lbmp));
		printf("height     : %u\n", lbmp_get_height(lbmp));
		printf("bpp        : %u\n", lbmp_get_bpp(lbmp));
	}
	lbmp_destroy(lbmp);
}
