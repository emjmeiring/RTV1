/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:46 by simzam            #+#    #+#             */
/*   Updated: 2016/07/04 12:09:44 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <stdio.h>

int		intersecting_sphere(t_scene *scene)
{
	t_quad	quad;
	t_vec3	dist;

	quad.a = vecdot(&scene->ray.ray_dir, &scene->ray.ray_dir);
	printf("A value is: %f\n", quad.a); 
	dist = vecsub(&scene->ray.rbegin, &scene->curr_sphere.loc);
	printf("Distance value is: %f\n", dist.x);
	quad.b = 2 * vecdot(&scene->ray.ray_dir, &dist);
	printf("B value is: %f\n", quad.b);
	quad.c = vecdot(&dist, &dist) - (scene->curr_sphere.radius *
				scene->curr_sphere.radius);
	printf("C value is: %f\n", quad.c);
	quad.discriminant = quad.b * quad.b - (4 * quad.a * quad.c);
	if (quad.discriminant < 0)
	{
		printf("Delta seems to be negative: %f\n", quad.discriminant);
		return (FALSE);
	}
	else
	{
		printf("Delta is greater than zero: %f\n", quad.discriminant);
		quad.sqrt_discrim = sqrt(quad.discriminant);
		quad.root1 = (-(quad.b * quad.b) + quad.sqrt_discrim) / 2;
		quad.root2 = (-(quad.b * quad.b) - quad.sqrt_discrim) / 2;
		if (quad.root1 > quad.root2)
			quad.root1 = quad.root2;
		if (quad.root1 > 0.001f && quad.root1 < quad.prev_root)
			quad.prev_root = quad.root1;
		else
			return (FALSE);
	}
	return (TRUE);
}
