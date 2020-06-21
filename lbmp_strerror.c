/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_strerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 01:30:57 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/21 04:39:10 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

const char	*lbmp_strerror(int code)
{
	if (code == LBMP_BPPERR)
		return ("ERROR: Only bpp 8, 16, 24 and 32 are impremented.\n");
	if (code == LBMP_FHEADERR)
		return ("ERROR: Error while read file header.");
	if (code == LBMP_IHEADERR)
		return ("ERROR: Error while read info header.");
	if (code == LBMP_MEMERR)
		return ("ERROR: Cannot allocate memory.");
	if (code == LBMP_OPERR)
		return ("ERROR: Cannot open file.");
	if (code == LBMP_COMPERR)
		return ("ERROR: Compressed bmp not implemented.");
	if (code == LBMP_PXLERR)
		return ("ERROR: Error while read pixel array.");
	return (NULL);
}
