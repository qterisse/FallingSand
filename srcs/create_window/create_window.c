/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:32:45 by panger            #+#    #+#             */
/*   Updated: 2024/01/24 17:17:42 by panger           ###   ########.fr       */
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
	vars->mouse_down = 0;
	return (vars);
}

void	create_image(t_vars *vars)
{
	vars->img->addr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->buffer = mlx_get_data_addr(vars->img->addr,
			&(vars->img->pixel_bits),
			&(vars->img->line_bytes),
			&(vars->img->endian));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->addr, 0, 0);
}

int	loop(t_vars *vars)
{
	// update_image(sand);
	// create_image(vars->grid, vars);
}

int	create_window(void)
{
	t_vars	vars;

	init_window(&vars);
	printf("1\n");
	create_image(&vars);
	printf("2\n");
	mlx_hook(vars.win, 04 ,(1L<<2), on_mouse_down_hook, &vars);
	mlx_hook(vars.win, 05 ,(1L<<3), on_mouse_up_hook, &vars);
	mlx_hook(vars.win, 06 ,(1L<<6), on_mouse_move_hook, &vars);
	// mlx_mouse_hook(vars.win, on_mouse_down_hook, &vars);
	printf("3\n");
	mlx_loop_hook(vars.mlx, loop, &vars);
	printf("4\n");
	mlx_loop(vars.mlx);
}