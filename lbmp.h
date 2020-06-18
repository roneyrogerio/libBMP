/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:55:23 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 00:59:30 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LBMP_H
# define LBMP_H
# include <inttypes.h>

void		*lbmp_load(char *pathname);
void		lbmp_destroy(void *lbmp);
uint32_t	lbmp_get_fheader_size(void *lbmp);
uint32_t	lbmp_get_fheader_reserved1(void *lbmp);
uint32_t	lbmp_get_fheader_reserved2(void *lbmp);
uint32_t	lbmp_get_fheader_offset(void *lbmp);
#endif
