/*
** inter_hyper_1_nappe.c for hyperboloide
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 19:11:34 2016 benjamin duhieu
** Last update Fri May 13 12:01:00 2016 benjamin duhieu
*/

#include "raytracer.h"

void		one_nappe(t_rt *s, t_hyper *hyper)
{
  t_2order	res;

  res.a = (CARRE(s->ray.vct->x) / CARRE(hyper->a)) +
    (CARRE(s->ray.vct->y) / CARRE(hyper->b)) -
    (CARRE(s->ray.vct->z) / CARRE(hyper->c));
  res.b = ((2 * s->ray.new_eye.x * s->ray.vct->x) / CARRE(hyper->a)) +
    ((2 * s->ray.new_eye.y * s->ray.vct->y) / CARRE(hyper->b)) -
    ((2 * s->ray.new_eye.z * s->ray.vct->z) / CARRE(hyper->b));
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(hyper->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(hyper->b)) -
    (CARRE(s->ray.new_eye.z) / CARRE(hyper->c)) - 1;
  second_order_solver(&res);
  if (res.root1 >= 0 && res.root2 >= 0)
    {
      if (res.root1 > res.root2)
	swap_value(&res.root1, &res.root2);
      hyper->k1 = res.root1;
      hyper->k2 = res.root2;
    }
  else if (res.root1 >= 0 && res.root2 < 0)
    hyper->k1 = res.root1;
  else if (res.root2 >= 0 && res.root1 < 0)
    hyper->k1 = res.root2;
}

void	two_nappe(t_rt *s, t_hyper *hyper)
{
  t_2order	res;

  res.a = (CARRE(s->ray.vct->x) / CARRE(hyper->a)) +
    (CARRE(s->ray.vct->y) / CARRE(hyper->b)) -
    (CARRE(s->ray.vct->z) / CARRE(hyper->c));
  res.b = ((2 * s->ray.new_eye.x * s->ray.vct->x) / CARRE(hyper->a)) +
    ((2 * s->ray.new_eye.y * s->ray.vct->y) / CARRE(hyper->b)) -
    ((2 * s->ray.new_eye.z * s->ray.vct->z) / CARRE(hyper->b));
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(hyper->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(hyper->b)) -
    (CARRE(s->ray.new_eye.z) / CARRE(hyper->c)) + 1;
  second_order_solver(&res);
  if (res.root1 >= 0 && res.root2 >= 0)
    {
      if (res.root1 > res.root2)
	swap_value(&res.root1, &res.root2);
      hyper->k1 = res.root1;
      hyper->k2 = res.root2;
    }
  else if (res.root1 >= 0 && res.root2 < 0)
    hyper->k1 = res.root1;
  else if (res.root2 >= 0 && res.root1 < 0)
    hyper->k1 = res.root2;
}

void	inter_hyper(t_rt *s, t_hyper *hyper)
{
  if (hyper->a && hyper->b && hyper->c)
    {
      if (hyper->nappe == 1)
	{
	  s->ray.new_eye.x = s->ray.eye.x - hyper->pos.x;
	  s->ray.new_eye.y = s->ray.eye.y - hyper->pos.y;
	  s->ray.new_eye.z = s->ray.eye.z - hyper->pos.z;
	  rotation(&s->rotation, s->ray.vct, &hyper->rot);
	  rotation(&s->rotation, &s->ray.new_eye, &hyper->rot);
	  one_nappe(s, hyper);
	}
      else if (hyper->nappe == 2)
	{
	  s->ray.new_eye.x = s->ray.eye.x - hyper->pos.x;
	  s->ray.new_eye.y = s->ray.eye.y - hyper->pos.y;
	  s->ray.new_eye.z = s->ray.eye.z - hyper->pos.z;
	  rotation(&s->rotation, s->ray.vct, &hyper->rot);
	  rotation(&s->rotation, &s->ray.new_eye, &hyper->rot);
	  two_nappe(s, hyper);
	}
    }
}
