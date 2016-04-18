/*
** shadow_limited_objects.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2/src
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 17 11:38:35 2016 romain samuel
** Last update Sun Apr 17 11:54:07 2016 romain samuel
*/

#include "raytracer.h"

double	shadow_limited_cylinder(t_rt *s, t_cylinder *cylinder, double k)
{
  if ((s->shade.shadow.simple_inter1.z < - cylinder->height &&
       s->shade.shadow.simple_inter2.z < - cylinder->height) ||
      (s->shade.shadow.simple_inter1.z > cylinder->height &&
       s->shade.shadow.simple_inter2.z > cylinder->height))
    return (0.0);
  return (k);
}

double	shadow_limited_cone(t_rt *s, t_cone *cone, double k)
{
  if (s->shade.shadow.simple_inter1.z < 0 ||
      (s->shade.shadow.simple_inter1.z > cone->height &&
       s->shade.shadow.simple_inter2.z > cone->height))
    return (0.0);
  return (k);
}
