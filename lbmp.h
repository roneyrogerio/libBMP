/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:55:23 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/02 06:24:52 by rde-oliv         ###   ########.fr       */
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
uint32_t	lbmp_get_pixel_color(void *lbmp, int x, int y);
int			lbmp_set_pixel_color(void *lbmp, int x, int y, uint32_t color);
void		*lbmp_new(int width, int height, int bpp);
int			lbmp_save(char *path, void *lbmp);
const char	*lbmp_strerror(int code);

# define LBMP_BPPERR 1
# define LBMP_FHEADERR 2
# define LBMP_IHEADERR 3
# define LBMP_MEMERR 4
# define LBMP_OPERR 5
# define LBMP_COMPERR 6
# define LBMP_PXLERR 7
# define LBMP_NULLERR 8
# define LBMP_WFHERR 9
# define LBMP_WIHERR 10
#endif
