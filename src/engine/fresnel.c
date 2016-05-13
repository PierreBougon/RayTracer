/*
** fresnel.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 18:50:48 2016 romain samuel
** Last update Wed May  4 18:53:32 2016 romain samuel
*/

#include "raytracer.h"

t_color		init_refraction(t_rt *s, t_acc *vct, t_acc eye)
{
  t_acc		new_vct;
  t_acc		new_eye;
  t_fresnel	f;
  t_color	color;

  if (s->hit.k1 > 0.00001 && s->hit.k2 > 0.00001)
    {
      s->hit.k1 = 0.0;
      s->hit.k2 = 0.0;
      s->ray.eye = eye;
      s->ray.vct = vct;
      s->ftabs.inters_ftab[s->obj_hit->next->type - 2](s, s->obj_hit->next);
      new_eye.x = eye.x + s->hit.k1 * vct->x;
      new_eye.y = eye.y + s->hit.k1 * vct->y;
      new_eye.z = eye.z + s->hit.k1 * vct->z;
      s->hit.norm.x = - s->hit.norm.x;
      s->hit.norm.y = - s->hit.norm.y;
      s->hit.norm.z = - s->hit.norm.z;
      f = get_refracted_vec(s, &s->hit.norm, s->hit.n2, 1);
      if (f.reflectance == 1.0)
	return (init_refraction(s, &f.reflection_vct, new_eye));
      else
	new_vct = f.refraction_vct;
    }
  else
    {
      new_vct = *vct;
      new_eye = eye;
    }
  s->obj_hit = NULL;
  color = display_objects(s, &new_vct, new_eye);
  return (color);
}

int		fresnel_computation(t_rt *s)
{
  t_acc		reflection_vct;
  t_acc		refraction_vct;
  t_fresnel	f;
  t_color	color;
  t_color	refraction_color;
  t_color	reflection_color;
  t_color	diffuse_color;
  double	reflection;
  double	opacity;
  t_acc		inter;

  diffuse_color = s->final_color;
  reflection = s->hit.reflection;
  opacity = s->hit.opacity;
  inter = s->shade.inter;
  f = get_refracted_vec(s, &s->hit.norm, 1, s->hit.n2);
  refraction_vct.x = f.refraction_vct.x;
  refraction_vct.y = f.refraction_vct.y;
  refraction_vct.z = f.refraction_vct.z;
  reflection_vct.x = f.reflection_vct.x;
  reflection_vct.y = f.reflection_vct.y;
  reflection_vct.z = f.reflection_vct.z;
  s->rec++;
  refraction_color.full = BLACK;
  reflection_color.full = BLACK;
  refraction_color = init_refraction(s, &refraction_vct, s->shade.inter);
  s->obj_hit = NULL;
  reflection_color = display_objects(s, &reflection_vct, inter);
  refraction_color = compute_colors(refraction_color, reflection_color, f.reflectance);
  color = compute_colors(diffuse_color, refraction_color, 1.0 - opacity);
  color = compute_colors(color, reflection_color, reflection);
  s->final_color = color;
  return (0);
}
