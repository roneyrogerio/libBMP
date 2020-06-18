/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 21:08:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 00:56:26 by rde-oliv         ###   ########.fr       */
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
		printf("%u\n", lbmp_get_fheader_size(lbmp));
		printf("%u\n", lbmp_get_fheader_reserved1(lbmp));
		printf("%u\n", lbmp_get_fheader_reserved2(lbmp));
		printf("%u\n", lbmp_get_fheader_offset(lbmp));
	}
	lbmp_destroy(lbmp);
}
