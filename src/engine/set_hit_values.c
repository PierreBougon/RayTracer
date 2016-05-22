/*
** set_hit_values.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 16:47:40 2016 romain samuel
** Last update Sun May 22 14:55:05 2016 romain samuel
*/

#include "raytracer.h"

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

void		set_hit_values_from_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*cylinder;

  cylinder = obj->datas;
  s->hit.k1 = cylinder->k1;
  s->hit.k2 = cylinder->k2;
  s->hit.simple_inter1 = cylinder->simple_inter1;
  s->hit.simple_inter2 = cylinder->simple_inter2;
  s->hit.norm1 = cylinder->norm1;
  s->hit.norm2 = cylinder->norm2;
  s->hit.brightness = cylinder->brightness;
  s->hit.ka = cylinder->ka;
  s->hit.kd = cylinder->kd;
  s->hit.ks = cylinder->ks;
  s->hit.opacity = cylinder->opacity;
  s->hit.reflection = cylinder->reflection;
  s->hit.n2 = cylinder->refraction;
  s->hit.limited = cylinder->limited;
  s->final_color = cylinder->color1;
  if (s->hit.limited == 0)
    {
      s->hit.color1 = cylinder->color1;
      s->hit.color2 = cylinder->color2;
    }
  if (s->hit.limited == 1)
    {
      s->hit.color1 = cylinder->color2;
      s->hit.color2 = cylinder->color1;
    }
  s->hit.tex_type = cylinder->tex_type;
  s->hit.texture1 = cylinder->texture1;
  s->hit.texture2 = cylinder->texture2;
  if (s->hit.limited == 0)
    get_texels_cylinder(s, cylinder);
  else
    get_texels_cyl_plan(s, cylinder);
}

void		set_hit_values_from_cone(t_rt *s, t_object *obj)
{
  t_cone	*cone;

  cone = obj->datas;
  s->hit.k1 = cone->k1;
  s->hit.k2 = cone->k2;
  s->hit.simple_inter1 = cone->simple_inter1;
  s->hit.simple_inter2 = cone->simple_inter2;
  s->hit.norm1 = cone->norm1;
  s->hit.norm2 = cone->norm2;
  s->hit.brightness = cone->brightness;
  s->hit.ka = cone->ka;
  s->hit.kd = cone->kd;
  s->hit.ks = cone->ks;
  s->hit.reflection = cone->reflection;
  s->hit.opacity = cone->opacity;
  s->hit.n2 = cone->refraction;
  s->hit.limited = cone->limited;
  s->final_color = cone->color1;
  s->hit.color1 = cone->color1;
  s->hit.color2 = cone->color2;
  s->hit.tex_type = cone->tex_type;
  s->hit.texture1 = cone->texture1;
  s->hit.texture2 = cone->texture2;
}

void		set_hit_values_from_plan(t_rt *s, t_object *obj)
{
  t_plan	*plan;

  plan = obj->datas;
  s->hit.k1 = plan->k1;
  s->hit.k2 = plan->k2;
  s->hit.simple_inter1 = plan->simple_inter1;
  s->hit.simple_inter2 = plan->simple_inter2;
  s->hit.norm1 = plan->norm;
  s->hit.brightness = plan->brightness;
  s->hit.ka = plan->ka;
  s->hit.kd = plan->kd;
  s->hit.ks = plan->ks;
  s->hit.reflection = plan->reflection;
  s->hit.opacity = plan->opacity;
  s->hit.n2 = plan->refraction;
  s->hit.color1 = plan->color1;
  s->hit.color2 = plan->color2;
  s->final_color = plan->color1;
  s->hit.tex_type = plan->tex_type;
  s->hit.texture1 = plan->texture;
  get_texels_plan(s, plan);
}

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
  /* get_texels_plan(s, plan); */
}

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

int	set_hit_values(t_rt *s, t_object *obj)
{
  s->ftabs.hit_ftab[0] = &set_hit_values_from_sphere;
  s->ftabs.hit_ftab[1] = &set_hit_values_from_cylinder;
  s->ftabs.hit_ftab[2] = &set_hit_values_from_cone;
  s->ftabs.hit_ftab[3] = &set_hit_values_from_plan;
  s->ftabs.hit_ftab[4] = &set_hit_values_from_tore;
  s->ftabs.hit_ftab[5] = &set_hit_values_from_box;
  s->ftabs.hit_ftab[6] = &set_hit_values_from_hole_cube;
  s->ftabs.hit_ftab[7] = &set_hit_values_from_hyper;
  s->ftabs.hit_ftab[8] = &set_hit_values_from_parab;
  s->ftabs.hit_ftab[obj->type - 1](s, obj);
  return (0);
}
