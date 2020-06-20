/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbmp_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 23:17:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/20 01:10:44 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LBMP_INT_H
# define LBMP_INT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <inttypes.h>

typedef struct	s_lbmp_file_header
{
	uint16_t	type;
	uint32_t	size;
	uint16_t	reserved1;
	uint16_t	reserved2;
	uint32_t	offset;
}				t_lbmp_file_header;

typedef struct	s_lbmp_info_header
{
	uint32_t	info_size;
	uint32_t	width;
	uint32_t	height;
	uint16_t	planes;
	uint16_t	bpp;
	uint32_t	compression;
	uint32_t	img_size;
	uint32_t	x_pels_per_meter;
	uint32_t	y_pels_per_meter;
	uint32_t	clr_used;
	uint32_t	clr_important;
}				t_lbmp_info_header;

typedef struct	s_lbmp
{
	t_lbmp_file_header	fheader;
	t_lbmp_info_header	iheader;
	void				*data;
}				t_lbmp;

int				lbmp_int_read_16(int fd, uint16_t *buffer);
int				lbmp_int_read_32(int fd, uint32_t *buffer);
int				lbmp_destroy(t_lbmp *lbmp);
int				lbmp_int_load_fheader(t_lbmp_file_header *fheader, int fd);
int				lbmp_int_load_iheader(t_lbmp_info_header *iheader, int fd);
int				lbmp_int_load_pixels(int fd, t_lbmp *lbmp);
int				lbmp_int_offset(int fd, int offset);
void			lbmp_int_bzero(t_lbmp *lbmp);
#endif
