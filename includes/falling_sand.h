/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   falling_sand.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:15 by panger            #+#    #+#             */
/*   Updated: 2024/01/24 15:51:43 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FALLING_SAND_H
# define FALLING_SAND_H

# include <unistd.h>
# include <mlx.h>

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
}				t_vars;

typedef struct s_param
{
	t_vars		*vars;
	vartype		**grid;
}			t_param;

#endif