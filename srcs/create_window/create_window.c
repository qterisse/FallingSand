/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:32:45 by panger            #+#    #+#             */
/*   Updated: 2024/01/26 10:42:23 by panger           ###   ########.fr       */
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
	vars->size = 1;
	vars->color = 0xFFFFFF;
	return (vars);
}

void	create_image(t_vars *vars)
{
	vars->img->addr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->buffer = mlx_get_data_addr(vars->img->addr,
			&(vars->img->pixel_bits),
			&(vars->img->line_bytes),
			&(vars->img->endian));
	draw_grid(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->addr, 0, 0);
}

void	update_sand(t_vars *vars)
{
	int	i;
	int	j;

	i = GRID_HEIGHT - 2;
	while (i >= 0)
	{
		j = GRID_WIDTH - 1;
		while (j >= 0)
		{
			if (vars->grid[i][j] != 0 && vars->grid[i + 1][j] == 0)
			{
				vars->grid[i + 1][j] = vars->grid[i][j];
				vars->grid[i][j] = 0;
			}
			j--;
		}
		i--;
	}
}

int	loop(t_vars *vars)
{
	update_sand(vars);
	draw_grid(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->addr, 0, 0);
}

int	create_window(void)
{
	t_vars	vars;

	init_window(&vars);
	create_image(&vars);
	mlx_hook(vars.win, 04 ,(1L<<2), on_mouse_down_hook, &vars);
	mlx_hook(vars.win, 05 ,(1L<<3), on_mouse_up_hook, &vars);
	mlx_hook(vars.win, 06 ,(1L<<6), on_mouse_move_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, loop, &vars);
	mlx_loop(vars.mlx);
}