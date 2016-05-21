/*
** inter_parab.c for parab
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 20:39:26 2016 benjamin duhieu
** Last update Sat May 21 10:43:50 2016 benjamin duhieu
*/

#include "raytracer.h"

int		parab_ellip(t_rt *s, t_parab *parab)
{
  t_2order	res;

  res.a = (CARRE(s->ray.vct->x) / CARRE(parab->a)) +
    (CARRE(s->ray.vct->y) / CARRE(parab->b));
  res.b = 2 * (((s->ray.vct->x * s->ray.new_eye.x) / CARRE(parab->a)) +
	       ((s->ray.vct->y * s->ray.new_eye.y) / CARRE(parab->b))) -
    (s->ray.vct->z / parab->c);
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(parab->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(parab->b)) -
    (s->ray.new_eye.z / parab->c);
  if ((res.delta = CARRE(res.b) - 4.0 * res.a * res.c) < 0.0001)
    return (0);
  s->hit.k1 = (- res.b + sqrt(res.delta)) / (2.0 * res.a);
  s->hit.k2 = (- res.b - sqrt(res.delta)) / (2.0 * res.a);
  return (0);
}

int	parab_hyper(t_rt *s, t_parab *parab)
{
  t_2order	res;

  res.a = (CARRE(s->ray.vct->x) / CARRE(parab->a)) -
    (CARRE(s->ray.vct->y) / CARRE(parab->b));
  res.b = 2 * (((s->ray.vct->x * s->ray.new_eye.x) / CARRE(parab->a)) -
	       ((s->ray.vct->y * s->ray.new_eye.y) / CARRE(parab->b))) -
    (s->ray.vct->z / parab->c);
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(parab->a)) -
    (CARRE(s->ray.new_eye.y) / CARRE(parab->b)) -
    (s->ray.new_eye.z / parab->c);
  if ((res.delta = CARRE(res.b) - 4.0 * res.a * res.c) < 0.0001)
    return (0);
  s->hit.k1 = (- res.b + sqrt(res.delta)) / (2.0 * res.a);
  s->hit.k2 = (- res.b - sqrt(res.delta)) / (2.0 * res.a);
  return (0);
}

void	inter_parab(t_rt *s, t_parab *parab)
{
  s->ray.new_eye.x = s->ray.eye.x - parab->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - parab->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - parab->pos.z;
  rotation(&s->rotation, s->ray.vct, &parab->rot);
  rotation(&s->rotation, &s->ray.new_eye, &parab->rot);
  if (parab->a != 0 && parab->b)
    {
      if (parab->form == 1)
	parab_ellip(s, parab);
      else if (parab->form == 2)
	parab_hyper(s, parab);
    }
}
