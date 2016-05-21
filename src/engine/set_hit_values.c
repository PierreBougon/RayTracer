/*
** set_hit_values.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 16:47:40 2016 romain samuel
** Last update Sat May 21 21:21:19 2016 romain samuel
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

int	set_hit_values(t_rt *s, t_object *obj)
{
  s->ftabs.hit_ftab[0] = &set_hit_values_from_sphere;
  s->ftabs.hit_ftab[1] = &set_hit_values_from_cylinder;
  s->ftabs.hit_ftab[2] = &set_hit_values_from_cone;
  s->ftabs.hit_ftab[3] = &set_hit_values_from_plan;
  s->ftabs.hit_ftab[4] = &set_hit_values_from_box;
  s->ftabs.hit_ftab[obj->type - 2](s, obj);
  return (0);
}
