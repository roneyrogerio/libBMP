/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_strerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 01:30:57 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/02 06:05:38 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

const char	*lbmp_strerror(int code)
{
	if (code == LBMP_BPPERR)
		return ("ERROR: Only bpp 24 and 32 are implemented.\n");
	if (code == LBMP_FHEADERR)
		return ("ERROR: Error while reading file header.\n");
	if (code == LBMP_IHEADERR)
		return ("ERROR: Error while reading info header.\n");
	if (code == LBMP_MEMERR)
		return ("ERROR: Cannot allocate memory.\n");
	if (code == LBMP_OPERR)
		return ("ERROR: Cannot open file.\n");
	if (code == LBMP_COMPERR)
		return ("ERROR: Compressed bmp not implemented.\n");
	if (code == LBMP_PXLERR)
		return ("ERROR: Error while reading pixel array.\n");
	if (code == LBMP_NULLERR)
		return ("ERROR: NULL lbmp pointer.\n");
	if (code == LBMP_WFHERR)
		return ("ERROR: error while writing file header.\n");
	if (code == LBMP_WIHERR)
		return ("ERROR: error while writing info header.\n");
	return (NULL);
}
