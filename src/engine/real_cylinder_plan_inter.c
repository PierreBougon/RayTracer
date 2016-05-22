/*
** real_cylinder_plan_inter.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May 18 19:57:39 2016 romain samuel
** Last update Sun May 22 14:53:42 2016 romain samuel
*/

#include "raytracer.h"

static int	get_si(t_rt *s)
{
  s->hit.simple_inter1.x = s->ray.new_eye.x + s->hit.k1 * s->ray.vct->x;
  s->hit.simple_inter1.y = s->ray.new_eye.y + s->hit.k1 * s->ray.vct->y;
  s->hit.simple_inter1.z = s->ray.new_eye.z + s->hit.k1 * s->ray.vct->z;
  return (0);
}

static int	cylinder_plan1_inter2(t_rt *s, t_cylinder *cylinder)
{
  t_plan	plan;
  t_acc		pos;

  s->hit.k2 = s->hit.k1;
  s->hit.simple_inter2 = s->hit.simple_inter1;
  s->hit.norm2 = s->hit.norm1;
  pos.x = 0;
  pos.y = 0;
  pos.z = cylinder->height;
  end_rotation(&s->rotation, &pos, &cylinder->rot);
  plan.pos.x = cylinder->pos.x + pos.x;
  plan.pos.y = cylinder->pos.y + pos.y;
  plan.pos.z = cylinder->pos.z + pos.z;
  plan.rot.x = cylinder->rot.x;
  plan.rot.y = cylinder->rot.y;
  plan.rot.z = cylinder->rot.z;
  inter_plan(s, &plan);
  get_si(s);
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm1);
  s->hit.simple_inter1.x += (double)pos.x;
  s->hit.simple_inter1.y += (double)pos.y;
  s->hit.simple_inter1.z += (double)pos.z;
  return (0);
}

static int	cylinder_plan2_inter2(t_rt *s, t_cylinder *cylinder)
{
  t_plan	plan;
  t_acc		pos;

  s->hit.k2 = s->hit.k1;
  s->hit.simple_inter2 = s->hit.simple_inter1;
  s->hit.norm2 = s->hit.norm1;
  pos.x = 0;
  pos.y = 0;
  pos.z = - cylinder->height;
  end_rotation(&s->rotation, &pos, &cylinder->rot);
  plan.pos.x = cylinder->pos.x + pos.x;
  plan.pos.y = cylinder->pos.y + pos.y;
  plan.pos.z = cylinder->pos.z + pos.z;
  plan.rot.x = cylinder->rot.x;
  plan.rot.y = cylinder->rot.y;
  plan.rot.z = cylinder->rot.z;
  inter_plan(s, &plan);
  get_si(s);
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm1);
  s->hit.simple_inter1.x += (double)pos.x;
  s->hit.simple_inter1.y += (double)pos.y;
  s->hit.simple_inter1.z += (double)pos.z;
  return (0);
}

int	cylinder_plans_inters(t_rt *s, t_cylinder *cylinder, t_object *obj)
{
  end_rotation(&s->rotation, s->ray.vct, &cylinder->rot);
  if (cylinder_plan1_inter2(s, cylinder) == -1 ||
      cylinder_plan2_inter2(s, cylinder) == -1)
    return (0);
  s->hit.limited = 1;
  cylinder->simple_inter1 = s->hit.simple_inter1;
  cylinder->simple_inter2 = s->hit.simple_inter2;
  cylinder->k1 = s->hit.k1;
  cylinder->k2 = s->hit.k2;
  cylinder->norm1 = s->hit.norm1;
  cylinder->norm2 = s->hit.norm2;
  cylinder->limited = s->hit.limited;
  s->hit.name = obj->name;
  update_hit_list(s, cylinder, 3, s->hit.k1);
  return (0);
}

int	csg_cylinder_plans_inters(t_rt *s, t_cylinder *cylinder, t_object *obj)
{
  end_rotation(&s->rotation, s->ray.vct, &cylinder->rot);
  if (cylinder_plan1_inter2(s, cylinder) == -1 ||
      cylinder_plan2_inter2(s, cylinder) == -1)
    return (0);
  s->hit.limited = 1;
  cylinder->simple_inter1 = s->hit.simple_inter1;
  cylinder->simple_inter2 = s->hit.simple_inter2;
  cylinder->k1 = s->hit.k1;
  cylinder->k2 = s->hit.k2;
  cylinder->norm1 = s->hit.norm1;
  cylinder->limited = s->hit.limited;
  fill_inter_list_cylinder(s, obj);
  s->hit.name = obj->name;
  return (0);
}
