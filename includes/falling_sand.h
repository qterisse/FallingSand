/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   falling_sand.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:15 by panger            #+#    #+#             */
/*   Updated: 2024/01/24 15:53:36 by panger           ###   ########.fr       */
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

#endif