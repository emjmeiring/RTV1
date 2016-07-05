/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 11:26:13 by simzam            #+#    #+#             */
/*   Updated: 2016/07/05 12:14:53 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	construct_an_image_and_put_it_on_window(t_scene *scene)
{
	int		pos;

	pos = (scene->x * scene->mlx.bpp / 8) + (scene->y * scene->mlx.size_line);
	scene->mlx.img_addr[pos] =
	mlx_get_color_value(&scene->mlx.mlx_con,
						(unsigned char)min(scene->colour.red * 255, 255));
	scene->mlx.img_addr[pos + 1]  =
	mlx_get_color_value(&scene->mlx.mlx_con,
						(unsigned char)min(scene->colour.green * 255, 255));
	scene->mlx.img_addr[pos + 2] =
	mlx_get_color_value(&scene->mlx.mlx_con,
                        (unsigned char)min(scene->colour.blue * 255, 255));
}

static void		find_material_to_determine_colour(t_scene *scene)
{
	scene->material =
	scene->materials[scene->spheres[scene->sp_id].material];
	find_value_of_light_at_this_point(scene);
}

static int		find_normal_for_this_new_vector_at_poi(t_scene *scene)
{
	t_vec3		scaled;
	t_vec3		new_begin;

	scaled = vecopx(&scene->ray.ray_dir, scene->t);
	new_begin = vecadd(&scene->ray.rbegin, &scaled);
	scene->vecnorm =
	vecsub(&new_begin, &scene->spheres[scene->sp_id].loc);
	scene->norm_dot_temp = vecdot(&(scene->vecnorm), &(scene->vecnorm));
	if (scene->norm_dot_temp == 0)
		return (-1);
	else
		return (42);
}

static int		find_closest_intersection(t_scene *scene)
{
	unsigned int	i;

	i = -1;
	scene->sp_id = -1;
	while (++i < 3)
	{
		scene->curr_sphere = scene->spheres[i];
		if (intersecting_sphere(scene))
			scene->sp_id = i;
	}
	if (scene->sp_id > 0)
		printf("sp_id: %d\n", scene->sp_id);
	return (scene->sp_id);
}

void	follow_up_on_the_ray(t_scene *scene)
{
	//scene->y = -1;
	while (++scene->y < HEIGH)
	{
		scene->x = -1;
		while (++scene->x < WIDTH)
		{
			initiate_vals(scene);
			while (scene->coef > 0.0f && scene->c_lvl < 15)
			{
				if (find_closest_intersection(scene) == -1)
					scene->c_lvl = 15;
				else if (find_normal_for_this_new_vector_at_poi(scene) == 42)
				{
					scene->norm_dot_temp = 1.0f / sqrtf(scene->norm_dot_temp);
					scene->vecnorm =
					vecopx(&scene->vecnorm, scene->norm_dot_temp);
					find_material_to_determine_colour(scene);
				}
			}
            construct_an_image_and_put_it_on_window(scene);
		}
	}
	mlx_put_image_to_window(scene->mlx.mlx_con,\
							scene->mlx.mlx_win,\
							scene->mlx.img, 0, 0);
}