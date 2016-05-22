/*
** limited_objects.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Apr 14 16:26:45 2016 romain samuel
** Last update Sun May 22 18:15:19 2016 benjamin duhieu
*/

#include "raytracer.h"

int		get_cylinder_plan1_inter1(t_rt *s, t_cylinder *cylinder)
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
  inter_plan(s, &plan);
  s->hit.limited = 1;
  s->hit.simple_inter1.x = s->ray.new_eye.x + s->hit.k1 * s->ray.vct->x;
  s->hit.simple_inter1.y = s->ray.new_eye.y + s->hit.k1 * s->ray.vct->y;
  s->hit.simple_inter1.z = s->ray.new_eye.z + s->hit.k1 * s->ray.vct->z;
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm1);
  return (0);
}

int		get_cylinder_plan2_inter1(t_rt *s, t_cylinder *cylinder)
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
  inter_plan(s, &plan);
  s->hit.limited = 1;
  s->hit.simple_inter1.x = s->ray.new_eye.x + s->hit.k1 * s->ray.vct->x;
  s->hit.simple_inter1.y = s->ray.new_eye.y + s->hit.k1 * s->ray.vct->y;
  s->hit.simple_inter1.z = s->ray.new_eye.z + s->hit.k1 * s->ray.vct->z;
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm1);
  return (0);
}

int	limited_cylinder(t_rt *s, t_cylinder *cylinder)
{
  if ((s->hit.simple_inter1.z < - cylinder->height &&
       s->hit.simple_inter2.z < - cylinder->height) ||
      (s->hit.simple_inter1.z > cylinder->height &&
       s->hit.simple_inter2.z > cylinder->height))
    return (-1);
  if (s->hit.simple_inter1.z < - cylinder->height)
    return (get_cylinder_plan2_inter1(s, cylinder));
  else if (s->hit.simple_inter1.z > cylinder->height)
    return (get_cylinder_plan1_inter1(s, cylinder));
  get_norm_cylinder(s, cylinder, &s->hit.norm1);
  return (0);
}

int		get_cone_plan_inter(t_rt *s, t_cone *cone)
{
  t_plan	plan;
  t_acc		pos;

  pos.x = 0;
  pos.y = 0;
  pos.z = - cone->height;
  end_rotation(&s->rotation, &pos, &cone->rot);
  plan.pos.x = cone->pos.x + pos.x;
  plan.pos.y = cone->pos.y + pos.y;
  plan.pos.z = cone->pos.z + pos.y;
  plan.rot.x = cone->rot.x;
  plan.rot.y = cone->rot.y;
  plan.rot.z = cone->rot.z;
  inter_plan(s, &plan);
  get_simple_inter(s, s->ray.vct, &s->ray.new_eye);
  end_rotation(&s->rotation, s->ray.vct, &plan.rot);
  get_norm_plan(s, &plan, &s->hit.norm1);
  s->hit.limited = 1;
  return (0);
}

int	limited_cone(t_rt *s, t_cone *cone)
{
  if (s->hit.simple_inter1.z < 0)
    return (-1);
  else if (s->hit.simple_inter1.z > cone->height)
    {
      if (s->hit.simple_inter2.z > 0.0 &&
	  s->hit.simple_inter2.z < cone->height)
	return (get_cone_plan_inter(s, cone));
      else
	return (-1);
    }
  get_norm_cone(s, cone, &s->hit.norm1);
  return (0);
}
