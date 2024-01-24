/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:37 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/24 17:17:18 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

void	put_pixel(t_img_vars *img, int x, int y, int color)
{
	int	pixel;

	pixel = (y * img->line_bytes) + (x * (img->pixel_bits / 8));
	if (img->endian == 1)
	{
		img->buffer[pixel + 0] = 255;
		img->buffer[pixel + 1] = color;
		img->buffer[pixel + 2] = color;
		img->buffer[pixel + 3] = color;
	}
	else if (img->endian == 0)
	{
		img->buffer[pixel + 0] = color;
		img->buffer[pixel + 1] = color;
		img->buffer[pixel + 2] = color;
		img->buffer[pixel + 3] = 255;
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
			put_pixel(img, x + (j++), y + i, 0xFFFFFF * filled);
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
			draw_rectangle(vars->img, x++, y, size, vars->grid == 1);
		y++;
	}
}
