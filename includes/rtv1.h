/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:21:15 by simzam            #+#    #+#             */
/*   Updated: 2016/07/04 13:22:47 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
#define RTV1_H
#define TRUE 1
#define FALSE 0
#define WIDTH 800
#define HEIGH 600
#include "vector.h"
#include <stdlib.h>
#include <mlx.h>

typedef struct 		s_light_channels
{
	float			red;
	float			green;
	float			blue;
}					t_colour;

typedef struct 		s_light_source_properties
{
	t_vec3			loc;
	t_colour		intensity;
}					t_light;

typedef struct 		s_reflectivity_and_diffuse
{
	t_colour		diffuse;
	float			reflection;
}					t_material;

typedef struct 		s_spherical_object
{
	t_vec3			loc;
	float			radius;
	int				material;
}					t_sphere;

typedef struct 		s_light_ray
{
	t_vec3			rbegin;
	t_vec3			ray_dir;
}					t_ray;

typedef struct 		mlx_connections_window_and_image_manager
{
	void			*mlx_con;
	void			*mlx_win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;


typedef struct 		s_environment
{
	int				x;
	int				y;
	int				c_lvl;
	float			coef;
	float			norm_dot_temp;
	t_mlx			mlx;
	t_ray			ray;
	t_ray			ray_scaled;
	t_vec3			ray_new_start;
	t_vec3			vecnorm;
	t_colour		colour;
	t_material		material;
	t_light			curr_light;
	t_sphere		curr_sphere;
	t_light			*lights;
	t_material		*materials;
	t_sphere		*spheres;
	int				sp_id;
	float			t;
}					t_scene;

int					is_intersecting_sphere(t_ray *ray, t_sphere);
int					intersecting_sphere(t_scene *scene);
void				init_all(t_scene *scene);
void				find_value_of_light_at_this_point(t_scene *scene);
void				initiate_vals(t_scene *scene);
void				saveppm(char *filename, unsigned char *img, int width, int height);
#endif
