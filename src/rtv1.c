/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:49:29 by simzam            #+#    #+#             */
/*   Updated: 2016/07/05 12:11:55 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				main(void)
{
	t_scene		scene;

	init_all(&scene);
	follow_up_on_the_ray(&scene);
	mlx_loop(scene.mlx.mlx_con);
	/*free(scene.mlx.mlx_con);
	free(scene.mlx.mlx_win);
	free(scene.mlx.img_addr);
	free(scene.spheres);
	free(scene.lights);
	free(scene.materials);*/
	return (0);
}
