/*
** get_texels.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 24 17:59:06 2016 romain samuel
** Last update Sun May 22 16:38:54 2016 romain samuel
*/

#include "raytracer.h"

void		get_texels_plan(t_rt *s, t_plan *plan)
{
  s->hit.texels.x = (plan->simple_inter1.x + (plan->width / 2))
    / plan->width;
  s->hit.texels.y = (plan->simple_inter1.y + (plan->height / 2))
    / plan->height;
}

void		get_texels_sphere(t_rt *s, t_sphere *sphere)
{
  double	col;
  double	theta;
  double	r;

  r = sqrt((sphere->simple_inter1.x * sphere->simple_inter1.x)
	   + (sphere->simple_inter1.y * sphere->simple_inter1.y)
	   + (sphere->simple_inter1.z * sphere->simple_inter1.z));
  col = acos(sphere->simple_inter1.y / r);
  if (sphere->simple_inter1.x >= 0)
    theta = acos(sphere->simple_inter1.z
		 / sqrt(pow(sphere->simple_inter1.z, 2)
			+ pow(sphere->simple_inter1.x, 2)));
  else
    theta = (2 * M_PI)
      - acos(sphere->simple_inter1.z
	     / sqrt(pow(sphere->simple_inter1.z, 2)
		    + pow(sphere->simple_inter1.x, 2)));
  s->hit.texels.x = theta / (2 * M_PI);
  s->hit.texels.y = col / M_PI;
}

void	get_texels_cyl_plan(t_rt *s, t_cylinder *cylinder)
{
  s->hit.texels.x = ((cylinder->simple_inter1.x / cylinder->size) + 1.0)
    / 2.0;
  s->hit.texels.y = ((cylinder->simple_inter1.y / cylinder->size) + 1.0)
    / 2.0;
  /* s->hit.texels.x = (cylinder->simple_inter1.x + (cylinder->size / 2)) */
  /*   / cylinder->size; */
  /* s->hit.texels.y = (cylinder->simple_inter1.y + (cylinder->size / 2)) */
  /*   / cylinder->size; */
}

void	get_texels_cylinder(t_rt *s, t_cylinder *cylinder)
{
  double	theta;
  double	y;

  if (s->hit.simple_inter1.x >= 0)
    theta = acos(cylinder->simple_inter1.y
		 / sqrt(pow(cylinder->simple_inter1.y, 2)
			+ pow(cylinder->simple_inter1.x, 2)));
  else
    theta = (2 * M_PI) - acos(cylinder->simple_inter1.y
			      / sqrt(pow(cylinder->simple_inter1.y, 2)
				     + pow(cylinder->simple_inter1.x, 2)));
  y = (cylinder->simple_inter1.z + cylinder->height) / (2 * cylinder->height);
  s->hit.texels.x = theta / (2 * M_PI);
  s->hit.texels.y = y;
}
