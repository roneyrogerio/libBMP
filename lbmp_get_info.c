/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_get_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 00:48:37 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 04:00:21 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

uint32_t	lbmp_get_bpp(t_lbmp *lbmp)
{
	return (lbmp->iheader.bpp);
}

uint32_t	lbmp_get_width(t_lbmp *lbmp)
{
	return (lbmp->iheader.width);
}

uint32_t	lbmp_get_height(t_lbmp *lbmp)
{
	return (lbmp->iheader.height);
}

uint32_t	lbmp_get_size(t_lbmp *lbmp)
{
	return (lbmp->fheader.size);
}
