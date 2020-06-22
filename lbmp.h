/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:55:23 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/21 21:11:44 by rde-oliv         ###   ########.fr       */
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
int			lbmp_get_pixel_color(void *lbmp, int x, int y);
int			lbmp_set_pixel_color(void *lbmp, int x, int y, uint32_t color);
void		*lbmp_new(int width, int height, int bpp);
int			lbmp_save(char *path, void *lbmp);
const char	*lbmp_strerror(int code);
#endif
