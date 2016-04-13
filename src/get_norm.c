/*
** get_norm.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 22:40:50 2016 romain samuel
** Last update Sun Apr 10 23:16:29 2016 romain samuel
*/

#include "raytracer.h"

void		get_norm_plan(t_rt *s)
{
  s->hit.norm.x = 0;
  s->hit.norm.y = 0;
  s->hit.norm.z = -100;
}

void		get_norm_sphere(t_rt *s)
{
  s->hit.norm.x = s->hit.simple_inter1.x;
  s->hit.norm.y = s->hit.simple_inter1.y;
  s->hit.norm.z = s->hit.simple_inter1.z;
}

void		get_norm_cylinder(t_rt *s)
{
  s->hit.norm.x = s->hit.simple_inter1.x;
  s->hit.norm.y = s->hit.simple_inter1.y;
  s->hit.norm.z = 0;
}

void		get_norm_cone(t_rt *s)
{
  s->hit.norm.x = s->hit.simple_inter1.x;
  s->hit.norm.y = s->hit.simple_inter1.y;
  s->hit.norm.z = - 0.1 * s->hit.simple_inter1.z;
}
