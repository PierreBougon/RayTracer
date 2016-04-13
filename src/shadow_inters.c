/*
** shadow_inters.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 16:12:34 2016 romain samuel
** Last update Mon Apr 11 18:03:43 2016 romain samuel
*/

#include "raytracer.h"

double		return_k(double k[2])
{
  if (k[0] < k[1] && k[0] > 0.000001)
    return (k[0]);
  else if (k[1] < k[0] && k[1] > 0.000001)
    return (k[1]);
  else
    return (-1);
}

double		shadow_inter_sphere(t_rt *s, t_sphere *sphere)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  t_acc		vct;
  t_acc		eye;
  double	k[2];

  eye = set_pos((double)(s->shade.light_pos.x - sphere->pos.x),
		(double)(s->shade.light_pos.y - sphere->pos.y),
		(double)(s->shade.light_pos.z - sphere->pos.z));
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  a = pow(vct.x, 2) + pow(vct.y, 2) + pow(vct.z, 2);
  b = 2 * (eye.x * vct.x + eye.y * vct.y + eye.z * vct.z);
  c = pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2) - pow(sphere->size, 2);
  if ((delta = pow(b, 2) - 4 * a * c) < 0.000001)
    return (0);
  k[0] = (- b + sqrt(delta)) / (2 * a);
  k[1] = (- b - sqrt(delta)) / (2 * a);
  return (return_k(k));
}

double		shadow_inter_cone(t_rt *s, t_cone *cone)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  double	angle;
  t_acc		vct;
  t_acc		eye;
  double	k[2];

  angle = cone->angle * M_PI / 180.0;
  eye = set_pos((double)(s->shade.light_pos.x - cone->pos.x),
		(double)(s->shade.light_pos.y - cone->pos.y),
		(double)(s->shade.light_pos.z - cone->pos.z));
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&vct, &cone->rot);
  rotation(&eye, &cone->rot);
  a = pow(vct.x, 2) + pow(vct.y, 2) - pow(vct.z, 2) / pow(tan(angle), 2);
  b = 2 * (vct.y * eye.y + vct.x * eye.x - (vct.z * eye.z)
	   / pow(tan(angle), 2));
  c = pow(eye.x, 2) + pow(eye.y, 2) - pow(eye.z, 2) / pow(tan(angle), 2);
  if ((delta = pow(b, 2) - 4 * a * c) < 0)
    return (0);
  k[0] = (- b + sqrt(delta)) / (2 * a);
  k[1] = (- b - sqrt(delta)) / (2 * a);
  return (return_k(k));
}

double		shadow_inter_cylinder(t_rt *s, t_cylinder *cylinder)
{
  double	delta;
  double	a;
  double	b;
  double	c;
  t_acc		vct;
  t_acc		eye;
  double	k[2];

  eye = set_pos((double)(s->shade.light_pos.x - cylinder->pos.x),
		(double)(s->shade.light_pos.y - cylinder->pos.y),
		(double)(s->shade.light_pos.z - cylinder->pos.z));
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&vct, &cylinder->rot);
  rotation(&eye, &cylinder->rot);
  a = pow(vct.x, 2) + pow(vct.y, 2);
  b = 2 * (vct.x * eye.x + vct.y * eye.y);
  c = pow(eye.x, 2) + pow(eye.y, 2) - pow(cylinder->size, 2);
  if ((delta = pow(b, 2) - 4 * a * c) < 0)
    return (0);
  k[0] = (- b + sqrt(delta)) / (2 * a);
  k[1] = (- b - sqrt(delta)) / (2 * a);
  return (return_k(k));
}

double		shadow_inter_plan(t_rt *s, t_plan *plan)
{
  t_acc		eye;
  t_acc		vct;
  double	k;

  eye = set_pos((double)(s->shade.light_pos.x - plan->pos.x),
		(double)(s->shade.light_pos.y - plan->pos.y),
		(double)(s->shade.light_pos.z - plan->pos.z));
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&vct, &plan->rot);
  rotation(&eye, &plan->rot);
  if (vct.z == 0.0)
    return (0);
  k = -1.0 * ((double)eye.z / vct.z);
  return (k);
}