/*
** inter_parab.c for parab
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 20:39:26 2016 benjamin duhieu
** Last update Mon May  2 21:31:07 2016 benjamin duhieu
*/

#include "raytracer.h"

void		parab_ellip(t_rt *s, t_parab *parab)
{
  t_2order	*res;

  res->a = (CARRE(s->ray.vct->x) / CARRE(parab->a)) +
    (CARRE(s->ray.vct->y) / CARRE(parab->b));
  res->b = ((2 * s->ray.vct->x) / CARRE(parab->a)) +
    ((2 * s->ray.vct->y) / CARRE(parab->b)) + s->ray.vct->z;
  res->c = (CARRE(s->ray.new_eye.x) / CARRE(parab->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(parab->b)) - s->ray.new_eye.z;
  second_order_solver(res);
}

void	parab_hyper(t_rt *s, t_parab *parab)
{
  t_2order	*res;

  res->a = (CARRE(s->ray.vct->x) / CARRE(parab->a)) -
    (CARRE(s->ray.vct->y) / CARRE(parab->b));
  res->b = ((2 * s->ray.vct->x) / CARRE(parab->a)) -
    ((2 * s->ray.vct->y) / CARRE(parab->b)) + s->ray.vct->z;
  res->c = (CARRE(s->ray.new_eye.x) / CARRE(parab->a)) -
    (CARRE(s->ray.new_eye.y) / CARRE(parab->b)) - s->ray.new_eye.z;
  second_order_solver(res);
}

void	inter_parab(t_rt *s, t_parab *parab)
{
  if (parab->form == 1)
    {
      s->ray.new_eye.x = s->ray.eye.x - parab->pos.x;
      s->ray.new_eye.y = s->ray.eye.y - parab->pos.y;
      s->ray.new_eye.z = s->ray.eye.z - parab->pos.z;
      rotation(&s->rotation, s->ray.vct, &parab->rot);
      rotation(&s->rotation, &s->ray.new_eye, &parab->rot);
      parab_ellip(s, parab);
    }
  else if (parab->form == 2)
    {
      s->ray.new_eye.x = s->ray.eye.x - parab->pos.x;
      s->ray.new_eye.y = s->ray.eye.y - parab->pos.y;
      s->ray.new_eye.z = s->ray.eye.z - parab->pos.z;
      rotation(&s->rotation, s->ray.vct, &parab->rot);
      rotation(&s->rotation, &s->ray.new_eye, &parab->rot);
      parab_hyper(s, parab);
    }
}
