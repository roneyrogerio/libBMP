/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_int_offset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 01:09:20 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/20 00:04:05 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

/*
**I can use fseek!
*/

int	lbmp_int_offset(int fd, int offset)
{
	char	*buffer;

	if (fd < 1 || offset == 0)
		return (0);
	buffer = (char *)malloc(offset * sizeof(char));
	if (!buffer || read(fd, buffer, offset) < offset)
		return (-1);
	free(buffer);
	return (0);
}
