/*
** set_hit_values.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 16:47:40 2016 romain samuel
** Last update Sun Apr 17 17:14:57 2016 romain samuel
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
  s->hit.norm = sphere->norm;
  s->hit.brightness = sphere->brightness;
  s->hit.ka = sphere->ka;
  s->hit.kd = sphere->kd;
  s->hit.ks = sphere->ks;
  s->hit.limited = 0;
  s->final_color = sphere->color;
}

void		set_hit_values_from_cylinder(t_rt *s, t_object *obj)
{
  t_cylinder	*cylinder;

  cylinder = obj->datas;
  s->hit.k1 = cylinder->k1;
  s->hit.k2 = cylinder->k2;
  s->hit.simple_inter1 = cylinder->simple_inter1;
  s->hit.simple_inter2 = cylinder->simple_inter2;
  s->hit.norm = cylinder->norm;
  s->hit.brightness = cylinder->brightness;
  s->hit.ka = cylinder->ka;
  s->hit.kd = cylinder->kd;
  s->hit.ks = cylinder->ks;
  s->hit.limited = cylinder->limited;
  s->final_color = cylinder->color;
}

void		set_hit_values_from_cone(t_rt *s, t_object *obj)
{
  t_cone	*cone;

  cone = obj->datas;
  s->hit.k1 = cone->k1;
  s->hit.k2 = cone->k2;
  s->hit.simple_inter1 = cone->simple_inter1;
  s->hit.simple_inter2 = cone->simple_inter2;
  s->hit.norm = cone->norm;
  s->hit.brightness = cone->brightness;
  s->hit.ka = cone->ka;
  s->hit.kd = cone->kd;
  s->hit.ks = cone->ks;
  s->hit.limited = cone->limited;
  s->final_color = cone->color;
}

void		set_hit_values_from_plan(t_rt *s, t_object *obj)
{
  t_plan	*plan;

  plan = obj->datas;
  s->hit.k1 = plan->k1;
  s->hit.k2 = plan->k2;
  s->hit.simple_inter1 = plan->simple_inter1;
  s->hit.simple_inter2 = plan->simple_inter2;
  s->hit.norm = plan->norm;
  s->hit.brightness = plan->brightness;
  s->hit.ka = plan->ka;
  s->hit.kd = plan->kd;
  s->hit.ks = plan->ks;
  s->final_color = plan->color1;
}

int	set_hit_values(t_rt *s, t_object *obj)
{
  s->ftabs.hit_ftab[0] = &set_hit_values_from_sphere;
  s->ftabs.hit_ftab[1] = &set_hit_values_from_cylinder;
  s->ftabs.hit_ftab[2] = &set_hit_values_from_cone;
  s->ftabs.hit_ftab[3] = &set_hit_values_from_plan;
  s->ftabs.hit_ftab[obj->type - 1](s, obj);
  return (0);
}
