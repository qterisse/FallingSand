/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   falling_sand.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:15 by panger            #+#    #+#             */
/*   Updated: 2024/01/24 16:46:37 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FALLING_SAND_H
# define FALLING_SAND_H

# include <unistd.h>
# include <mlx.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <stdint.h>

# define GRID_WIDTH 100
# define GRID_HEIGHT 100

# define WIDTH 1000
# define HEIGHT 1000

typedef char vartype;

typedef struct s_img_vars
{
	void	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}			t_img_vars;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img_vars	*img;
	vartype		**grid;
}				t_vars;

void	free_grid(vartype **grid, int height);
vartype	**init_grid(int width, int height);

#endif