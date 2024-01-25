/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:43 by panger            #+#    #+#             */
/*   Updated: 2024/01/25 13:53:24 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/falling_sand.h"

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

void	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_SPACE)
	{
		vars->color->r = rand() % (255 - 1) + 1;
	}
}
