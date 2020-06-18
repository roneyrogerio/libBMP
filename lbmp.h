/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:55:23 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/18 03:58:19 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LBMP_H
# define LBMP_H
# include <inttypes.h>

void		*lbmp_load(char *pathname);
int			lbmp_destroy(void *lbmp);
uint32_t	lbmp_get_size(void *lbmp);
uint32_t	lbmp_get_width(void *lbmp);
uint32_t	lbmp_get_height(void *lbmp);
uint32_t	lbmp_get_bpp(void *lbmp);
#endif
