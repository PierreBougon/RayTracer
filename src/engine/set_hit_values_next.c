/*
** set_hit_values_next.c for set_next in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun May 22 11:47:48 2016 benjamin duhieu
** Last update Sun May 22 17:24:53 2016 marc brout
*/

#include "raytracer.h"

void		set_hit_values_from_tore(t_rt *s, t_object *obj)
{
  t_tore	*tore;

  tore = obj->datas;
  s->hit.k1 = tore->inter.k1;
  s->hit.k2 = tore->inter.k2;
  s->hit.k3 = tore->inter.k3;
  s->hit.k4 = tore->inter.k4;
  s->hit.simple_inter1 = tore->simple_inter1;
  s->hit.simple_inter2 = tore->simple_inter2;
  s->hit.simple_inter3 = tore->simple_inter3;
  s->hit.simple_inter4 = tore->simple_inter4;
  s->hit.norm1 = tore->norm;
  s->hit.brightness = tore->brightness;
  s->hit.ka = tore->ka;
  s->hit.kd = tore->kd;
  s->hit.ks = tore->ks;
  s->hit.reflection = tore->reflection;
  s->hit.opacity = tore->opacity;
  s->hit.n2 = tore->refraction;
  s->hit.color1 = tore->color1;
  s->hit.color2 = tore->color2;
  s->final_color = tore->color1;
  s->hit.tex_type = tore->tex_type;
  s->hit.texture1 = tore->texture;
}

void		set_hit_values_from_hole_cube(t_rt *s, t_object *obj)
{
  t_hole_cube	*hole_cube;

  hole_cube = obj->datas;
  s->hit.k1 = hole_cube->inter.k1;
  s->hit.k2 = hole_cube->inter.k2;
  s->hit.k3 = hole_cube->inter.k3;
  s->hit.k4 = hole_cube->inter.k4;
  s->hit.simple_inter1 = hole_cube->simple_inter1;
  s->hit.simple_inter2 = hole_cube->simple_inter2;
  s->hit.simple_inter3 = hole_cube->simple_inter3;
  s->hit.simple_inter4 = hole_cube->simple_inter4;
  s->hit.norm1 = hole_cube->norm;
  s->hit.brightness = hole_cube->brightness;
  s->hit.ka = hole_cube->ka;
  s->hit.kd = hole_cube->kd;
  s->hit.ks = hole_cube->ks;
  s->hit.reflection = hole_cube->reflection;
  s->hit.opacity = hole_cube->opacity;
  s->hit.n2 = hole_cube->refraction;
  s->hit.color1 = hole_cube->color1;
  s->hit.color2 = hole_cube->color2;
  s->final_color = hole_cube->color1;
  s->hit.tex_type = hole_cube->tex_type;
  s->hit.texture1 = hole_cube->texture;
}

void		set_hit_values_from_hyper(t_rt *s, t_object *obj)
{
  t_hyper	*hyper;

  hyper = obj->datas;
  s->hit.k1 = hyper->k1;
  s->hit.k2 = hyper->k2;
  s->hit.simple_inter1 = hyper->simple_inter1;
  s->hit.simple_inter2 = hyper->simple_inter2;
  s->hit.norm1 = hyper->norm;
  s->hit.brightness = hyper->brightness;
  s->hit.ka = hyper->ka;
  s->hit.kd = hyper->kd;
  s->hit.ks = hyper->ks;
  s->hit.reflection = hyper->reflection;
  s->hit.opacity = hyper->opacity;
  s->hit.n2 = hyper->refraction;
  s->hit.color1 = hyper->color1;
  s->hit.color2 = hyper->color2;
  s->final_color = hyper->color1;
  s->hit.tex_type = hyper->tex_type;
  s->hit.texture1 = hyper->texture;
}

void		set_hit_values_from_parab(t_rt *s, t_object *obj)
{
  t_parab	*parab;

  parab = obj->datas;
  s->hit.k1 = parab->k1;
  s->hit.k2 = parab->k2;
  s->hit.simple_inter1 = parab->simple_inter1;
  s->hit.simple_inter2 = parab->simple_inter2;
  s->hit.norm1 = parab->norm;
  s->hit.brightness = parab->brightness;
  s->hit.ka = parab->ka;
  s->hit.kd = parab->kd;
  s->hit.ks = parab->ks;
  s->hit.reflection = parab->reflection;
  s->hit.opacity = parab->opacity;
  s->hit.n2 = parab->refraction;
  s->hit.color1 = parab->color1;
  s->hit.color2 = parab->color2;
  s->final_color = parab->color1;
  s->hit.tex_type = parab->tex_type;
  s->hit.texture1 = parab->texture;
}

void		set_hit_values_from_ellip(t_rt *s, t_object *obj)
{
  t_ellip	*ellip;

  ellip = obj->datas;
  s->hit.k1 = ellip->k1;
  s->hit.k2 = ellip->k2;
  s->hit.simple_inter1 = ellip->simple_inter1;
  s->hit.simple_inter2 = ellip->simple_inter2;
  s->hit.norm1 = ellip->norm;
  s->hit.brightness = ellip->brightness;
  s->hit.ka = ellip->ka;
  s->hit.kd = ellip->kd;
  s->hit.ks = ellip->ks;
  s->hit.reflection = ellip->reflection;
  s->hit.opacity = ellip->opacity;
  s->hit.n2 = ellip->refraction;
  s->hit.color1 = ellip->color1;
  s->hit.color2 = ellip->color2;
  s->final_color = ellip->color1;
  s->hit.tex_type = ellip->tex_type;
  s->hit.texture1 = ellip->texture;
}
