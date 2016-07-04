#include "rtv1.h"

static void		get_reflected_start_and_end_position(t_scene *scene)
{
	float	reflect;
	t_vec3	temp;

	scene->ray.rbegin = scene->ray_new_start;
	reflect = 2.0f * vecdot(&scene->ray.ray_dir, &scene->vecnorm);
	temp = vecopx(&scene->ray.ray_dir, reflect);
	scene->c_lvl++;
}

static void		get_lambert_diffusion(t_scene *scene, t_ray *light_ray)
{
	float	lambert;

	lambert = vecdot(&scene->vecnorm, &light_ray->ray_dir) * scene->coef;
	scene->colour.red =
	lambert + scene->curr_light.intensity.red * scene->material.diffuse.red;
	scene->colour.green =
	lambert + scene->curr_light.intensity.green * scene->material.diffuse.green;
	scene->colour.blue =
	lambert + scene->curr_light.intensity.blue * scene->material.diffuse.blue;
}

void			find_value_of_light_at_this_point(t_scene *scene)
{
	unsigned int	j;
	t_vec3			distance;
	t_ray			light_ray;
	float			t;

	j = -1;
	while (++j < 3)
	{
		scene->curr_light = scene->lights[j];
		vecsub(&scene->curr_light.loc, &scene->ray_new_start);
		if (vecdot(&distance, &scene->vecnorm) > 0.0f)
		{
			t = sqrt(vecdot(&distance, &distance));
			if (t > 0.0f)
			{
				light_ray.rbegin = scene->ray_new_start;
				light_ray.ray_dir = vecopx(&distance, (1 / t));
				get_lambert_diffusion(scene, &light_ray);
			}
		}
	}
	scene->coef *= scene->material.reflection;
	get_reflected_start_and_end_position(scene);
}
