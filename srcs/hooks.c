/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:43 by panger            #+#    #+#             */
/*   Updated: 2024/01/25 13:52:49 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

void	on_mouse_down_hook(int button, int x, int y, void *vars)
{
	t_vars	*tmp;
	int		i;
	int		j;

	tmp = vars;
	if (button == 4 && tmp->size < 10)
		tmp->size += 1;
	if (button == 5 && tmp->size > 1)
		tmp->size -= 1;
	if (button == 1)
	{
		i = 0;
		while (i < tmp->size)
		{
			j = 0;
			while (j < tmp->size)
			{
				tmp->grid[((y * GRID_WIDTH) / WIDTH) + i][((x * GRID_WIDTH) / WIDTH) + j] = 1;
				j++;
			}
			i++;
		}
		tmp->mouse_down = 1;
	}
}

void	on_mouse_up_hook(int button, int x, int y, void *vars)
{
	t_vars *tmp;

	tmp = vars;
	if (button == 1)
		tmp->mouse_down = 0;
}

void	on_mouse_move_hook(int x, int y, void *vars)
{
	t_vars *tmp;
	int		i;
	int		j;

	tmp = vars;
	if (tmp->mouse_down == 1)
	{
		i = 0;
		while (i < tmp->size)
		{
			j = 0;
			while (j < tmp->size)
			{
				tmp->grid[((y * GRID_WIDTH) / WIDTH) + i][((x * GRID_WIDTH) / WIDTH) + j] = 1;
				j++;
			}
			i++;
		}
	}
}
