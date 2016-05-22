/*
** second_inter_limited_objects.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May 18 16:34:15 2016 romain samuel
** Last update Sun May 22 21:42:10 2016 benjamin duhieu
*/

#include "raytracer.h"

int		inter_plan2(t_rt *s, t_plan *plan)
{
  s->ray.new_eye.x = (double)(s->ray.eye.x - plan->pos.x);
  s->ray.new_eye.y = (double)(s->ray.eye.y - plan->pos.y);
  s->ray.new_eye.z = (double)(s->ray.eye.z - plan->pos.z);
  rotation(&s->rotation, s->ray.vct, &plan->rot);
  rotation(&s->rotation, &s->ray.new_eye, &plan->rot);
  if (s->ray.vct->z == 0.0)
    return (0);
  s->hit.k2 = -1.0 * ((double)s->ray.new_eye.z / s->ray.vct->z);
  return (0);
}

int		get_cylinder_plan1_inter2(t_rt *s, t_cylinder *cylinder)
{
  t_plan	plan;
  t_acc		pos;

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
  inter_plan2(s, &plan);
  s->hit.simple_inter2.x = s->ray.new_eye.x + s->hit.k2 * s->ray.vct->x;
  s->hit.simple_inter2.y = s->ray.new_eye.y + s->hit.k2 * s->ray.vct->y;
  s->hit.simple_inter2.z = s->ray.new_eye.z + s->hit.k2 * s->ray.vct->z;
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm2);
  return (0);
}

int		get_cylinder_plan2_inter2(t_rt *s, t_cylinder *cylinder)
{
  t_plan	plan;
  t_acc		pos;

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
  inter_plan2(s, &plan);
  s->hit.simple_inter2.x = s->ray.new_eye.x + s->hit.k2 * s->ray.vct->x;
  s->hit.simple_inter2.y = s->ray.new_eye.y + s->hit.k2 * s->ray.vct->y;
  s->hit.simple_inter2.z = s->ray.new_eye.z + s->hit.k2 * s->ray.vct->z;
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm2);
  return (0);
}

int	limited_cylinder2(t_rt *s, t_cylinder *cylinder)
{
  if ((s->hit.simple_inter1.z < - cylinder->height &&
       s->hit.simple_inter2.z < - cylinder->height) ||
      (s->hit.simple_inter1.z > cylinder->height &&
       s->hit.simple_inter2.z > cylinder->height))
    return (-1);
  else if (s->hit.simple_inter2.z < - cylinder->height)
    return (get_cylinder_plan2_inter2(s, cylinder));
  else if (s->hit.simple_inter2.z > cylinder->height)
    return (get_cylinder_plan1_inter2(s, cylinder));
  get_norm_cylinder(s, cylinder, &s->hit.norm2);
  return (0);
}
