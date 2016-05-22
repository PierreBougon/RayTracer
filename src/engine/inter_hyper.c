/*
** inter_hyper_1_nappe.c for hyperboloide
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 19:11:34 2016 benjamin duhieu
** Last update Sun May 22 15:47:28 2016 benjamin duhieu
*/

#include "raytracer.h"

int		one_nappe(t_rt *s, t_hyper *hyper)
{
  t_2order	res;

  res.a = (CARRE(s->ray.vct->x) / CARRE(hyper->a)) +
    (CARRE(s->ray.vct->y) / CARRE(hyper->b)) -
    (CARRE(s->ray.vct->z) / CARRE(hyper->c));
  res.b = 2 * (((s->ray.vct->x * s->ray.new_eye.x) / CARRE(hyper->a)) +
	       ((s->ray.vct->y * s->ray.new_eye.y) / CARRE(hyper->b)) -
	       ((s->ray.vct->z * s->ray.new_eye.z) / CARRE(hyper->c)));
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(hyper->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(hyper->b)) -
    (CARRE(s->ray.new_eye.z) / CARRE(hyper->c)) - 1;
  if ((res.delta = CARRE(res.b) - 4.0 * res.a * res.c) < 0.0001)
    return (0);
  s->hit.k1 = (- res.b + sqrt(res.delta)) / (2.0 * res.a);
  s->hit.k2 = (- res.b - sqrt(res.delta)) / (2.0 * res.a);
  return (0);
}

int		two_nappe(t_rt *s, t_hyper *hyper)
{
  t_2order	res;

  res.a = (CARRE(s->ray.vct->x) / CARRE(hyper->a)) +
    (CARRE(s->ray.vct->y) / CARRE(hyper->b)) -
    (CARRE(s->ray.vct->z) / CARRE(hyper->c));
  res.b = 2 * (((s->ray.vct->x * s->ray.new_eye.x) / CARRE(hyper->a)) +
	       ((s->ray.vct->y * s->ray.new_eye.y) / CARRE(hyper->b)) -
	       ((s->ray.vct->z * s->ray.new_eye.z) / CARRE(hyper->c)));
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(hyper->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(hyper->b)) -
    (CARRE(s->ray.new_eye.z) / CARRE(hyper->c)) + 1;
  if ((res.delta = CARRE(res.b) - 4.0 * res.a * res.c) < 0.0001)
    return (0);
  s->hit.k1 = (- res.b + sqrt(res.delta)) / (2.0 * res.a);
  s->hit.k2 = (- res.b - sqrt(res.delta)) / (2.0 * res.a);
  return (0);
}

void	inter_hyper(t_rt *s, t_hyper *hyper)
{
  s->ray.new_eye.x = s->ray.eye.x - hyper->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - hyper->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - hyper->pos.z;
  rotation(&s->rotation, s->ray.vct, &hyper->rot);
  rotation(&s->rotation, &s->ray.new_eye, &hyper->rot);
  if (hyper->a && hyper->b && hyper->c)
    {
      if (hyper->nappe == 1)
	one_nappe(s, hyper);
      else if (hyper->nappe == 2)
	two_nappe(s, hyper);
    }
}
