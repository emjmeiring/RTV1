/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:23 by simzam            #+#    #+#             */
/*   Updated: 2016/07/04 11:36:28 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		initiate_vals(t_scene *scene)
{
	scene->colour.red = 0;
	scene->colour.green = 0;
	scene->colour.blue = 0;
	scene->c_lvl = 0;
	scene->coef = 1.0f;
	scene->ray.rbegin.x = scene->x;
	scene->ray.rbegin.y = scene->y;
	scene->ray.rbegin.z = -2000;
	scene->ray.ray_dir.x = 0;
	scene->ray.ray_dir.y = 0;
	scene->ray.ray_dir.z = 1;
}

static void		init_material(t_material **materials)
{
	(*materials)[0].diffuse.red = 1;
	(*materials)[0].diffuse.green = 0;
	(*materials)[0].diffuse.blue = 0;
	(*materials)[0].reflection = 0.2f;
	(*materials)[1].diffuse.red = 0;
	(*materials)[1].diffuse.green = 1;
	(*materials)[1].diffuse.blue = 0;
	(*materials)[1].reflection = 0.5f;
	(*materials)[2].diffuse.red = 0;
	(*materials)[2].diffuse.green = 0;
	(*materials)[2].diffuse.blue = 1;
	(*materials)[2].reflection = 0.9f;
}

static void		init_sphere(t_sphere **spheres)
{
	(*spheres)[0].loc.x = 200;
	(*spheres)[0].loc.y = 300;
	(*spheres)[0].loc.z = 0;
	(*spheres)[0].radius = 100;
	(*spheres)[0].material = 0;
	(*spheres)[1].loc.x = 400;
	(*spheres)[1].loc.y = 400;
	(*spheres)[1].loc.z = 0;
	(*spheres)[1].radius = 100;
	(*spheres)[1].material = 1;
	(*spheres)[2].loc.x = 500;
	(*spheres)[2].loc.y = 350;
	(*spheres)[2].loc.z = 0;
	(*spheres)[2].radius = 100;
	(*spheres)[2].material = 2;
}

static void		init_lights(t_light **lights)
{
	(*lights)[0].loc.x = 0;
	(*lights)[0].loc.y = 240;
	(*lights)[0].loc.z = -100;
	(*lights)[0].intensity.red = 1;
	(*lights)[0].intensity.green = 1;
	(*lights)[0].intensity.blue = 1;
	(*lights)[1].loc.x = 3200;
	(*lights)[1].loc.y = 3000;
	(*lights)[1].loc.z = -1000;
	(*lights)[1].intensity.red = 0.6f;
	(*lights)[1].intensity.green = 0.7f;
	(*lights)[1].intensity.blue = 1;
	(*lights)[2].loc.x = 600;
	(*lights)[2].loc.y = 0;
	(*lights)[2].loc.z = -100;
	(*lights)[2].intensity.red = 0.3f;
	(*lights)[2].intensity.green = 0.5f;
	(*lights)[2].intensity.blue = 1;
}

static void		init_mlx(t_mlx *mlx)
{
	mlx->mlx_con = (void *)malloc(sizeof(void *));
	mlx->mlx_win = (void *)malloc(sizeof(void *));
	mlx->img = (void *)malloc(4096);
	mlx->mlx_con = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_con, WIDTH, HEIGH,
					"<The Raytracer/>");
}

void			init_all(t_scene *scene)
{
	scene->y = 0;
	scene->t = 20000.0f;
	scene->sp_id = -1;
	scene->spheres = (t_sphere *)malloc(sizeof(t_sphere));
	scene->lights = (t_light *)malloc(sizeof(t_light));
	scene->materials = (t_material *)malloc(sizeof(t_material));
	init_material(&scene->materials);
	init_sphere(&scene->spheres);
	init_lights(&scene->lights);
	init_mlx(&scene->mlx);
}
