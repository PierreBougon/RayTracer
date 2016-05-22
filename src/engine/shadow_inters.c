/*
** shadow_inters.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 16:12:34 2016 romain samuel
** Last update Sun May 22 14:18:15 2016 marc brout
*/

#include "raytracer.h"

double		return_k(double k[2])
{
  if (k[0] <= k[1] && k[0] > 0.000001)
    return (k[0]);
  else if (k[1] <= k[0] && k[1] > 0.000001)
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

  eye.x = (double)(s->shade.light_pos.x - sphere->pos.x);
  eye.y = (double)(s->shade.light_pos.y - sphere->pos.y);
  eye.z = (double)(s->shade.light_pos.z - sphere->pos.z);
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  a = CARRE(vct.x) + CARRE(vct.y) + CARRE(vct.z);
  b = 2 * (eye.x * vct.x + eye.y * vct.y + eye.z * vct.z);
  c = CARRE(eye.x) + CARRE(eye.y) + CARRE(eye.z) -
    CARRE(sphere->size);
  if ((delta = CARRE(b) - 4 * a * c) < 0.000001)
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
  eye.x = (double)(s->shade.light_pos.x - cone->pos.x);
  eye.y = (double)(s->shade.light_pos.y - cone->pos.y);
  eye.z = (double)(s->shade.light_pos.z - cone->pos.z);
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&s->rotation, &vct, &cone->rot);
  rotation(&s->rotation, &eye, &cone->rot);
  a = CARRE(vct.x) + CARRE(vct.y) - CARRE(vct.z) / CARRE(tan(angle));
  b = 2 * (vct.y * eye.y + vct.x * eye.x - (vct.z * eye.z)
	   / CARRE(tan(angle)));
  c = CARRE(eye.x) + CARRE(eye.y) - CARRE(eye.z) / CARRE(tan(angle));
  if ((delta = CARRE(b) - 4 * a * c) < 0)
    return (0);
  k[0] = (- b + sqrt(delta)) / (2 * a);
  k[1] = (- b - sqrt(delta)) / (2 * a);
  return (shadow_simple_inters(s, &vct, &eye, k));
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

  eye.x = (double)(s->shade.light_pos.x - cylinder->pos.x);
  eye.y = (double)(s->shade.light_pos.y - cylinder->pos.y);
  eye.z = (double)(s->shade.light_pos.z - cylinder->pos.z);
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&s->rotation, &vct, &cylinder->rot);
  rotation(&s->rotation, &eye, &cylinder->rot);
  a = CARRE(vct.x) + CARRE(vct.y);
  b = 2 * (vct.x * eye.x + vct.y * eye.y);
  c = CARRE(eye.x) + CARRE(eye.y) - CARRE(cylinder->size);
  if ((delta = CARRE(b) - 4 * a * c) < 0)
    return (0);
  k[0] = (- b + sqrt(delta)) / (2 * a);
  k[1] = (- b - sqrt(delta)) / (2 * a);
  return (shadow_simple_inters(s, &vct, &eye, k));
}

double		shadow_inter_plan(t_rt *s, t_plan *plan)
{
  t_acc		eye;
  t_acc		vct;
  double	k;

  eye.x = (double)(s->shade.light_pos.x - plan->pos.x);
  eye.y = (double)(s->shade.light_pos.y - plan->pos.y);
  eye.z = (double)(s->shade.light_pos.z - plan->pos.z);
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&s->rotation, &vct, &plan->rot);
  rotation(&s->rotation, &eye, &plan->rot);
  if (vct.z == 0.0)
    return (0);
  k = -1.0 * ((double)eye.z / vct.z);
  return (shadow_simple_inter_plan(s, &vct, &eye, k));
}
