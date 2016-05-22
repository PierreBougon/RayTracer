/*
** get_norm.c<RAYTRACER> for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 22:40:50 2016 romain samuel
** Last update Sun May 22 21:35:19 2016 benjamin duhieu
*/

#include "raytracer.h"

void		get_norm_plan(t_rt *s, t_plan *plan, t_acc *norm)
{
  norm->x = 0;
  norm->y = 0;
  norm->z = -100;
  end_rotation(&s->rotation, norm, &plan->rot);
}

void		get_norm_sphere(t_rt *s, t_acc *norm)
{
  norm->x = s->hit.simple_inter1.x;
  norm->y = s->hit.simple_inter1.y;
  norm->z = s->hit.simple_inter1.z;
}

void		get_norm_cylinder(t_rt *s, t_cylinder *cylinder, t_acc *norm)
{
  norm->x = s->hit.simple_inter1.x;
  norm->y = s->hit.simple_inter1.y;
  norm->z = 0;
  end_rotation(&s->rotation, norm, &cylinder->rot);
}

void		get_norm_cone(t_rt *s, t_cone *cone, t_acc *norm)
{
  norm->x = s->hit.simple_inter1.x;
  norm->y = s->hit.simple_inter1.y;
  norm->z = - 0.1 * s->hit.simple_inter1.z;
  end_rotation(&s->rotation, norm, &cone->rot);
}
