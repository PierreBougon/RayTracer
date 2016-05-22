/*
** inter_ellip.c for inter_ellip in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun May 22 13:38:20 2016 benjamin duhieu
** Last update Sun May 22 14:57:54 2016 benjamin duhieu
*/

#include "raytracer.h"

int		inter_ellip(t_rt *s, t_ellip *ellip)
{
  t_2order	res;

  s->ray.new_eye.x = s->ray.eye.x - ellip->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - ellip->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - ellip->pos.z;
  rotation(&s->rotation, s->ray.vct, &ellip->rot);
  rotation(&s->rotation, &s->ray.new_eye, &ellip->rot);
  res.a = (CARRE(s->ray.vct->x) / CARRE(ellip->a)) +
    (CARRE(s->ray.vct->y) / CARRE(ellip->b)) +
    (CARRE(s->ray.vct->z) / CARRE(ellip->c));
  res.b = 2 * (((s->ray.vct->x * s->ray.new_eye.x) / CARRE(ellip->a)) +
	       ((s->ray.vct->y * s->ray.new_eye.y) / CARRE(ellip->b)) +
	       ((s->ray.vct->z * s->ray.new_eye.z) / CARRE(ellip->c)));
  res.c = (CARRE(s->ray.new_eye.x) / CARRE(ellip->a)) +
    (CARRE(s->ray.new_eye.y) / CARRE(ellip->b)) +
    (CARRE(s->ray.new_eye.z) / CARRE(ellip->c)) - 1;
  if ((res.delta = CARRE(res.b) - (4.0 * res.a * res.c)) < 0.0001)
    return (0);
  s->hit.k1 = (-res.b + sqrt(res.delta)) / (2.0 * res.a);
  s->hit.k2 = (-res.b - sqrt(res.delta)) / (2.0 * res.a);
  return (0);
}
