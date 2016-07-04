#include "rtv1.h"

int		intersecting_sphere(t_scene *scene)
{
	t_quad	quad;
	t_vec3	dist;

	quad.a = vecdot(&scene->ray.ray_dir, &scene->ray.ray_dir);
	dist = vecsub(&scene->ray.rbegin, &scene->curr_sphere.loc);
	quad.b = vecdot(&scene->ray.ray_dir, &dist);
	quad.c = vecdot(&dist, &dist) - (scene->curr_sphere.radius * scene->curr_sphere.radius);
	quad.discriminant = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.discriminant < 0)
		return (FALSE);
	else
	{
		quad.sqrt_discrim = sqrt(quad.discriminant);
		quad.root1 = (-quad.b + quad.sqrt_discrim) / 2;
		quad.root2 = (-quad.b - quad.sqrt_discrim) / 2;
		if (quad.root1 > quad.root2)
			quad.root1 = quad.root2;
		if (quad.root1 > 0.001f && quad.root1 < quad.prev_root)
			quad.prev_root = quad.prev_root;
		else
			return (FALSE);
	}
	return (TRUE);
}
