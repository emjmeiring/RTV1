/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:49:29 by simzam            #+#    #+#             */
/*   Updated: 2016/07/04 11:35:29 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static int		find_closest_intersection(t_scene *scene)
{
	unsigned int	i;

	i = -1;
	scene->sp_id = -1;
	while (++i < 3)
		if (intersecting_sphere(scene))
			scene->sp_id = i;
	return (scene->sp_id);
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

static void		find_material_to_determine_colour(t_scene *scene)
{
	scene->material =
	scene->materials[scene->spheres[scene->sp_id].material];
	find_value_of_light_at_this_point(scene);
}

int				main(void)
{
	t_scene		scene;

	init_all(&scene);
	while (++scene.y < HEIGH)
	{
		scene.x = -1;
		while (++scene.x < WIDTH)
		{
			scene.c_lvl = 0;
			scene.coef = 1.0f;
			initiate_vals(&scene);
			while (scene.coef > 0.0f && scene.c_lvl < 15)
			{
				if (find_closest_intersection(&scene) == -1)
					scene.c_lvl = 15;
				else if (find_normal_for_this_new_vector_at_poi(&scene) == 42)
				{
					scene.norm_dot_temp = 1.0f / sqrtf(scene.norm_dot_temp);
					scene.vecnorm = vecopx(&scene.vecnorm, scene.norm_dot_temp);
					find_material_to_determine_colour(&scene);
				}
			}
		}
	}
	return (0);
}
