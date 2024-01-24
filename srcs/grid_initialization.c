/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:34 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/24 17:42:53 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

void	free_grid(vartype **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

vartype	**init_grid(int width, int height)
{
	vartype	**grid;
	int		y;
	int		x;

	y = 0;
	grid = malloc(sizeof(vartype *) * height);
	if (!grid)
		return (NULL);
	while (y < height)
	{
		grid[y] = malloc(sizeof(vartype) * width);
		if (!grid[y])
			return (free_grid(grid, y), NULL);
		x = 0;
		while (x < width)
			grid[y][x++] = 0;
		y++;
	}
	return (grid);
}
