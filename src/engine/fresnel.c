/*
** fresnel.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 18:50:48 2016 romain samuel
** Last update Sun May 22 19:34:04 2016 romain samuel
*/

#include "raytracer.h"

int		fresnel_computation(t_rt *s)
{
  t_acc		reflection_vct;
  t_fresnel	f;
  t_color	color;
  t_color	reflection_color;
  t_color	diffuse_color;
  double	reflection;
  t_acc		inter;

  s->rec++;
  if (s->rec > 1)
    return (0);
  diffuse_color = s->final_color;
  f = get_refracted_vec(s, &s->hit.norm1, 1, s->hit.n2);
  reflection = s->hit.reflection;
  inter = s->shade.inter;
  reflection_vct.x = f.reflection_vct.x;
  reflection_vct.y = f.reflection_vct.y;
  reflection_vct.z = f.reflection_vct.z;
  reflection_color.full = BLACK;
  clear_list(s->obj_hit);
  s->obj_hit = NULL;
  reflection_color = display_objects(s, &reflection_vct, inter);
  color = compute_colors(diffuse_color, reflection_color, reflection);
  s->final_color = color;
  return (0);
}
