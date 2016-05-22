/*
** set_hit_values_sphere.c for rt2 in gfx_raytracer2/src
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 17:21:43 2016 marc brout
** Last update Sun May 22 17:25:25 2016 marc brout
*/

#include "raytracer.h"

void		set_hit_values_from_box(t_rt *s, t_object *obj)
{
  t_box		*box;

  box = obj->datas;
  s->hit.k1 = box->k1;
  s->hit.k2 = box->k2;
  s->hit.simple_inter1 = box->simple_inter1;
  s->hit.simple_inter2 = box->simple_inter2;
  s->hit.norm1 = box->norm1;
  s->hit.norm2 = box->norm2;
  s->hit.brightness = box->brightness;
  s->hit.ka = box->ka;
  s->hit.kd = box->kd;
  s->hit.ks = box->ks;
  s->hit.reflection = box->reflection;
  s->hit.opacity = box->opacity;
  s->hit.n2 = box->refraction;
  s->hit.color1 = box->color1;
  s->hit.color2 = box->color2;
  s->final_color = box->color1;
  s->hit.tex_type = box->tex_type;
  s->hit.texture1 = box->texture;
}

void		set_hit_values_from_sphere(t_rt *s, t_object *obj)
{
  t_sphere	*sphere;

  sphere = obj->datas;
  s->hit.k1 = sphere->k1;
  s->hit.k2 = sphere->k2;
  s->hit.simple_inter1 = sphere->simple_inter1;
  s->hit.simple_inter2 = sphere->simple_inter2;
  s->hit.norm1 = sphere->norm1;
  s->hit.norm2 = sphere->norm2;
  s->hit.brightness = sphere->brightness;
  s->hit.ka = sphere->ka;
  s->hit.kd = sphere->kd;
  s->hit.ks = sphere->ks;
  s->hit.reflection = sphere->reflection;
  s->hit.opacity = sphere->opacity;
  s->hit.n2 = sphere->refraction;
  s->hit.limited = 0;
  s->final_color = sphere->color1;
  s->hit.color1 = sphere->color1;
  s->hit.color2 = sphere->color2;
  s->hit.tex_type = sphere->tex_type;
  s->hit.texture1 = sphere->texture;
  get_texels_sphere(s, sphere);
}
