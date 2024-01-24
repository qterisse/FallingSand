/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:32:45 by panger            #+#    #+#             */
/*   Updated: 2024/01/24 16:13:44 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "falling_sand.h"

t_vars	*init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "falling_sand");
	if (!(vars->win))
		exit(EXIT_FAILURE);
	vars->img = (t_img_vars *)malloc(sizeof(t_img_vars));
	if (!(vars->img))
		return (NULL);
	vars->grid = init_grid(GRID_WIDTH, GRID_HEIGHT);
	if (!vars->grid)
		return (free(vars->img), NULL);
	return (vars);
}

void	create_image(vartype ***map, t_vars *vars)
{
	vars->img->addr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->buffer = mlx_get_data_addr(vars->img->addr,
			&(vars->img->pixel_bits),
			&(vars->img->line_bytes),
			&(vars->img->endian));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->addr, 0, 0);
}

void	sand_to_img(t_vars *vars)
{
	
}

void	on_mouse_down_hook(int button, int x, int y, void *param)
{
	
}

int	loop(t_vars *vars)
{
	update_image(sand);
	create_image(vars->grid, vars);
	return (0);
}

int	create_window(vartype **grid)
{
	t_vars	vars;

	init_window(&vars);
	create_image(grid, &vars);
	mlx_hook(vars.win, 2, 1L << 0, on_mouse_down_hook, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars);
	
}