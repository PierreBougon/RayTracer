/*
** inters.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 18:31:08 2016 romain samuel
** Last update Thu Apr 14 16:05:16 2016 romain samuel
*/

#include "raytracer.h"

t_acc		set_pos(double x, double y, double z)
{
  t_acc		pos;

  pos.x = x;
  pos.y = y;
  pos.z = z;
  return (pos);
}

int		inter_plan(t_rt *s, t_plan *plan)
{
  s->ray.new_eye = set_pos((double)(s->ray.eye.x - plan->pos.x),
			   (double)(s->ray.eye.y - plan->pos.y),
			   (double)(s->ray.eye.z - plan->pos.z));
  rotation(s->ray.vct, &plan->rot);
  rotation(&s->ray.new_eye, &plan->rot);
  if (s->ray.vct->z == 0.0)
    return (0);
  s->hit.k1 = -1.0 * ((double)s->ray.new_eye.z / s->ray.vct->z);
  return (0);
}

int		inter_sphere(t_rt *s, t_sphere *sphere)
{
  double	delta;
  double	a;
  double	b;
  double	c;

  s->ray.new_eye = set_pos((double)(s->ray.eye.x - sphere->pos.x),
		(double)(s->ray.eye.y - sphere->pos.y),
		(double)(s->ray.eye.z - sphere->pos.z));
  a = pow(s->ray.vct->x, 2) + pow(s->ray.vct->y, 2) + pow(s->ray.vct->z, 2);
  b = 2 * (s->ray.new_eye.x * s->ray.vct->x + s->ray.new_eye.y
	   * s->ray.vct->y + s->ray.new_eye.z * s->ray.vct->z);
  c = pow(s->ray.new_eye.x, 2) + pow(s->ray.new_eye.y, 2)
    + pow(s->ray.new_eye.z, 2)
    - pow(sphere->size, 2);
  if ((delta = pow(b, 2) - 4 * a * c) < 0.0001)
    return (0);
  s->hit.k1 = (- b + sqrt(delta)) / (2 * a);
  s->hit.k2 = (- b - sqrt(delta)) / (2 * a);
  return (0);
}

int		inter_cone(t_rt *s, t_cone *cone)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  double	angle;

  angle = cone->angle * M_PI / 180.0;
  s->ray.new_eye = set_pos((double)(s->ray.eye.x - cone->pos.x),
		(double)(s->ray.eye.y - cone->pos.y),
		(double)(s->ray.eye.z - cone->pos.z));
  rotation(s->ray.vct, &cone->rot);
  rotation(&s->ray.new_eye, &cone->rot);
  a = pow(s->ray.vct->x, 2) + pow(s->ray.vct->y, 2)
    - pow(s->ray.vct->z, 2) / pow(tan(angle), 2);
  b = 2 * (s->ray.vct->y * s->ray.new_eye.y + s->ray.vct->x * s->ray.new_eye.x
	   - (s->ray.vct->z * s->ray.new_eye.z) / pow(tan(angle), 2));
  c = pow(s->ray.new_eye.x, 2) + pow(s->ray.new_eye.y, 2)
    - pow(s->ray.new_eye.z, 2) / pow(tan(angle), 2);
  if ((delta = pow(b, 2) - 4 * a * c) < 0)
    return (0);
  s->hit.k1 = (- b + sqrt(delta)) / (2 * a);
  s->hit.k2 = (- b - sqrt(delta)) / (2 * a);
  return (0);
}

int		inter_cylinder(t_rt *s, t_cylinder *cylinder)
{
  double	delta;
  double	a;
  double	b;
  double	c;

  s->ray.new_eye = set_pos((double)(s->ray.eye.x - cylinder->pos.x),
		(double)(s->ray.eye.y - cylinder->pos.y),
		(double)(s->ray.eye.z - cylinder->pos.z));
  rotation(s->ray.vct, &cylinder->rot);
  rotation(&s->ray.new_eye, &cylinder->rot);
  a = pow(s->ray.vct->x, 2) + pow(s->ray.vct->y, 2);
  b = 2 * (s->ray.vct->x * s->ray.new_eye.x + s->ray.vct->y
	   * s->ray.new_eye.y);
  c = pow(s->ray.new_eye.x, 2) + pow(s->ray.new_eye.y, 2)
    - pow(cylinder->size, 2);
  if ((delta = pow(b, 2) - 4 * a * c) < 0)
    return (0);
  s->hit.k1 = (- b + sqrt(delta)) / (2 * a);
  s->hit.k2 = (- b - sqrt(delta)) / (2 * a);
  return (0);
}
