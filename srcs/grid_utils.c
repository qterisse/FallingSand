/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:34 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/24 15:50:56 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

void	free_grid(int **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(grid[i++]);
	free(grid);
}

int	**init_grid(int **grid, int width, int height)
{
	int	**grid;
	int	y;

	y = 0;
	grid = malloc(sizeof(int *) * height);
	if (!grid)
		return (NULL);
	while (y < height)
	{
		grid[y] = malloc(sizeof(int) * width);
		if (!grid[y])
			return (free_grid(grid, y), NULL);
		y++;
	}
	return (grid);
}
