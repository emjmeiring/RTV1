/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:46 by simzam            #+#    #+#             */
/*   Updated: 2016/07/05 11:33:27 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		intersecting_sphere(t_scene *scene)
{
	scene->quad.a = vecdot(&scene->ray.ray_dir, &scene->ray.ray_dir);
	scene->dist = vecsub(&scene->ray.rbegin, &scene->curr_sphere.loc);
	scene->quad.b = 2.0f * vecdot(&scene->ray.ray_dir, &scene->dist);
	scene->quad.c = vecdot(&scene->dist, &scene->dist) -
	(scene->curr_sphere.radius * scene->curr_sphere.radius);
	scene->quad.discriminant = (scene->quad.b * scene->quad.b) -
	(4 * scene->quad.a * scene->quad.c);
	if (scene->quad.discriminant < 0)
		return (FALSE);
	else
	{
		scene->quad.sqrt_discrim = sqrt(scene->quad.discriminant);
		scene->quad.root1 = (-scene->quad.b + scene->quad.sqrt_discrim) / 2;
		scene->quad.root2 = (-scene->quad.b - scene->quad.sqrt_discrim) / 2;
		if (scene->quad.root1 > scene->quad.root2)
			scene->quad.root1 = scene->quad.root2;
		if (scene->quad.root1 > 0.001f && scene->quad.root1 <
			scene->quad.prev_root)
			scene->quad.prev_root = scene->quad.root1;
	}
	return (TRUE);
}
