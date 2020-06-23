/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:47:02 by tlernoul          #+#    #+#             */
/*   Updated: 2020/06/23 12:50:53 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

unsigned char	*read_pixel(int size, int fd, uint32_t offset)
{
	int				i;
	t_image			img;
	unsigned char	*ret;

	i = -1;
	ret = ft_memalloc(sizeof(unsigned char) * (size * 4) + 1);
	read(fd, &img, offset);
	while (++i < size)
	{
		read(fd, &img, sizeof(t_image));
		ret[i * 4 + 0] = img.r;
		ret[i * 4 + 1] = img.g;
		ret[i * 4 + 2] = img.b;
		ret[i * 4 + 3] = img.a;
		if (i <= 60)
			printf("%d %d %d %d\n", img.r, img.g, img.b, img.a); //TODO Fix me first ~20 bytes are wrong
	}
	return (ret);
}

void			ft_free_bmp(t_bmp *file)
{
	free(file->img);
	ft_memdel((void*)&file);
}

t_bmp			*ft_parse_bmp(char *pth)
{
	t_fileheader	header;
	t_bmp			*ret;
	int				fd;

	ret = ft_memalloc(sizeof(t_bmp));
	if ((!(fd = open(pth, O_RDONLY))) > 0)
		return (NULL);
	read(fd, &header, sizeof(t_fileheader));
	printf("\n%u\n", header.bitppx);
	if (header.type != 19778 ||
	header.width <= 0 || header.height <= 0 || header.bitppx != 32)
		return (NULL);
	ret->fheader = header;
	ret->img = read_pixel(header.height * header.width, fd, header.offset);
	return (ret);
}
