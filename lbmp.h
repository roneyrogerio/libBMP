/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:55:23 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/21 03:22:43 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LBMP_H
# define LBMP_H
# include <inttypes.h>

extern int	g_lbmperr;
void		*lbmp_load(char *pathname);
int			lbmp_destroy(void *lbmp);
uint32_t	lbmp_get_size(void *lbmp);
uint32_t	lbmp_get_width(void *lbmp);
uint32_t	lbmp_get_height(void *lbmp);
uint32_t	lbmp_get_bpp(void *lbmp);
void		*lbmp_get_pixel_ptr(int x, int y, void *lbmp);
int			lbmp_get_pixel_color(void *ptr, int bpp);
int			lbmp_set_pixel_color(void *ptr, uint32_t new, int bpp);
void		*lbmp_new(int width, int height, int bpp);
int			lbmp_save(char *path, void *lbmp);
const char	*lbmp_strerror(int code);
#endif
