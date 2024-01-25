/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:37 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/25 14:29:33 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/falling_sand.h"

void	put_pixel(t_img_vars *img, int x, int y, int color)
{
	char	*pixel;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	pixel = img->buffer + (y * img->line_bytes) + (x * (img->pixel_bits / 8));
	*(unsigned int*)pixel = color;
}

void	draw_rectangle(t_img_vars *img, int x, int y, int size, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			put_pixel(img, x + (j++), y + i, color);
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
