/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:37 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/24 17:39:30 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

void	put_pixel(t_img_vars *img, int x, int y, unsigned char color)
{
	int	pixel;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	pixel = (y * img->line_bytes) + (x * (img->pixel_bits / 8));
	if (img->endian == 1)
	{
		img->buffer[pixel + 0] = (unsigned char) 255;
		img->buffer[pixel + 1] = color;
		img->buffer[pixel + 2] = color;
		img->buffer[pixel + 3] = color;
	}
	else if (img->endian == 0)
	{
		img->buffer[pixel + 0] = color;
		img->buffer[pixel + 1] = color;
		img->buffer[pixel + 2] = color;
		img->buffer[pixel + 3] = (unsigned char) 255;
	}
}

void	draw_rectangle(t_img_vars *img, int x, int y, int size, int filled)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			put_pixel(img, x + (j++), y + i, 255 * filled);
		i++;
	}
}

void	draw_grid(t_vars *vars)
{
	int	size;
	int	x;
	int	y;

	y = 0;
	size = WIDTH / GRID_WIDTH;
	while (y < GRID_HEIGHT)
	{
		x = 0;
		while (x < GRID_WIDTH)
		{
			draw_rectangle(vars->img, x * size, y * size, size, vars->grid[y][x]);
			x++;
		}
		y++;
	}
}
