/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:25:35 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/04 16:25:00 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "config.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

enum
{
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data		t_data;
typedef struct s_main		t_main;
typedef struct s_canvas		t_canvas;
typedef struct s_point		t_point;
typedef struct s_cam		t_cam;
typedef struct s_map		t_map;
typedef struct s_vectors	t_vectors;

struct						s_point
{
	double					x;
	double					y;
	double					z;
};

struct						s_vectors
{
	t_point					ex;
	t_point					ey;
	t_point					ez;
};

struct						s_canvas
{
	t_point					p;
	unsigned int			w;
	unsigned int			h;
	void					*img;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
};

struct						s_map
{
	size_t					w;
	size_t					h;
	char					**coords;
};

struct						s_cam
{
	float					mu;
	float					alpha;
	float					d;
	float					fx;
	float					fy;
	t_point					tr;
	t_point					ro;
	t_vectors				v;
	t_point					**coords;
};

struct						s_main
{
	t_canvas				canvas;
	int						x_pos;
	void					(*draw_on_screen)(t_data *);
	char					*map_path;
	t_cam					cam;
	t_map					map;
};

struct						s_data
{
	t_point					*p;
	void					*mlx;
	void					*win;
	t_main					main;
};

void		init(t_data *d, int i, char **v);
void		paint_pxl(t_canvas *canvas, int x, int y, int color);
void		register_events(t_data *data);
t_map		parse_map(char *map_path);
t_vectors	calculate_vectors(t_data *d);
void		register_events(t_data *data);
int			is_valid_map(char *map_path, t_map *map);
void		build_map(char *map_path, t_map *map);
t_map		parse_map(char *map_path);
t_point		transform_point(t_cam *cam, t_point p);
#endif
