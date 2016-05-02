/*
** limited_plan.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 25 17:38:32 2016 romain samuel
** Last update Mon Apr 25 17:50:21 2016 romain samuel
*/

#include "raytracer.h"

int	limited_plan(t_rt *s, t_plan *plan)
{
  if (s->hit.simple_inter1.y < - plan->height / 2 ||
      s->hit.simple_inter1.y > plan->height / 2 ||
      s->hit.simple_inter1.x < - plan->width / 2 ||
      s->hit.simple_inter1.x > plan->width / 2)
    return (-1);
  get_norm_plan(s, plan);
  return (0);
}
