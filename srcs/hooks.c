/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:43 by panger            #+#    #+#             */
/*   Updated: 2024/01/24 17:46:41 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

void	on_mouse_down_hook(int button, int x, int y, void *vars)
{
	t_vars *tmp;

	tmp = vars;
	if (button == 1)
	{
		tmp->grid[(y * GRID_WIDTH) / WIDTH][(x * GRID_WIDTH) / WIDTH] = 1;	
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

	tmp = vars;
	if (tmp->mouse_down == 1)
		tmp->grid[(y * GRID_WIDTH) / WIDTH][(x * GRID_WIDTH) / WIDTH] = 1;
}
