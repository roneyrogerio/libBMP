/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_get_fheader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 00:48:37 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 00:49:28 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lbmp_int.h"

uint32_t	lbmp_get_fheader_size(t_lbmp *lbmp)
{
	return (lbmp->fheader.size);
}

uint32_t	lbmp_get_fheader_reserved1(t_lbmp *lbmp)
{
	return (lbmp->fheader.reserved1);
}

uint32_t	lbmp_get_fheader_reserved2(t_lbmp *lbmp)
{
	return (lbmp->fheader.reserved2);
}

uint32_t	lbmp_get_fheader_offset(t_lbmp *lbmp)
{
	return (lbmp->fheader.offset);
}
