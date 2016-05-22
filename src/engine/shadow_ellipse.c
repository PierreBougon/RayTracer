/*
** shadow_ellipse.c in gfx_raytracer2/src/engine
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 15:49:26 2016 marc brout
** Last update Sun May 22 16:08:35 2016 marc brout
*/

#include "raytracer.h"

double		shadow_inter_ellip(t_rt *s, t_ellip *e)
{
  t_2order	res;
  t_acc		vct;
  t_acc		eye;
  double	k[2];

  eye.x = s->shade.light_pos.x - e->pos.x;
  eye.y = s->shade.light_pos.y - e->pos.y;
  eye.z = s->shade.light_pos.z - e->pos.z;
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&s->rotation, &vct, &e->rot);
  rotation(&s->rotation, &eye, &e->rot);
  res.a = (CARRE(vct.x) / CARRE(e->a)) +
    (CARRE(vct.y) / CARRE(e->b)) +
    (CARRE(vct.z) / CARRE(e->c));
  res.b = 2 * (((vct.x * eye.x) / CARRE(e->a)) +
	       ((vct.y * eye.y) / CARRE(e->b)) +
	       ((vct.z * eye.z) / CARRE(e->c)));
  res.c = (CARRE(eye.x) / CARRE(e->a)) +
    (CARRE(eye.y) / CARRE(e->b)) +
    (CARRE(eye.z) / CARRE(e->c)) - 1;
  if ((res.delta = CARRE(res.b) - (4.0 * res.a * res.c)) < 0.0001)
    return (-1);
  k[0] = (-res.b + sqrt(res.delta)) / (2.0 * res.a);
  k[1] = (-res.b - sqrt(res.delta)) / (2.0 * res.a);
  return (return_k(k));
}
