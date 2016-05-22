/*
** shadow_hyper.c for rt2 in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 13:22:19 2016 marc brout
** Last update Sun May 22 16:08:37 2016 marc brout
*/

#include "raytracer.h"

static double		_one_nappe(t_hyper *hyper,
				   t_acc *vct, t_acc *eye)
{
  hyper->res.a = (CARRE(vct->x) / CARRE(hyper->a)) +
    (CARRE(vct->y) / CARRE(hyper->b)) -
    (CARRE(vct->z) / CARRE(hyper->c));
  hyper->res.b = 2 * (((vct->x * eye->x) / CARRE(hyper->a)) +
	       ((vct->y * eye->y) / CARRE(hyper->b)) -
	       ((vct->z * eye->z) / CARRE(hyper->c)));
  hyper->res.c = (CARRE(eye->x) / CARRE(hyper->a)) +
    (CARRE(eye->y) / CARRE(hyper->b)) -
    (CARRE(eye->z) / CARRE(hyper->c)) - 1;
  if ((hyper->res.delta = CARRE(hyper->res.b) -
       4.0 * hyper->res.a * hyper->res.c) < 0.0001)
    return (1);
  return (0);
}

static int		_two_nappe(t_hyper *hyper,
				   t_acc *vct, t_acc *eye)
{
  hyper->res.a = (CARRE(vct->x) / CARRE(hyper->a)) +
    (CARRE(vct->y) / CARRE(hyper->b)) -
    (CARRE(vct->z) / CARRE(hyper->c));
  hyper->res.b = 2 * (((vct->x * eye->x) / CARRE(hyper->a)) +
	       ((vct->y * eye->y) / CARRE(hyper->b)) -
	       ((vct->z * eye->z) / CARRE(hyper->c)));
  hyper->res.c = (CARRE(eye->x) / CARRE(hyper->a)) +
    (CARRE(eye->y) / CARRE(hyper->b)) -
    (CARRE(eye->z) / CARRE(hyper->c)) + 1;
  if ((hyper->res.delta = CARRE(hyper->res.b) - 4.0 *
       hyper->res.a * hyper->res.c) < 0.0001)
    return (1);
  return (0);
}

double		shadow_inter_hyper(t_rt *s, t_hyper *h)
{
  t_acc		eye;
  t_acc		vct;
  int		ret;
  double	k[2];

  eye.x = s->shade.light_pos.x - h->pos.x;
  eye.y = s->shade.light_pos.y - h->pos.y;
  eye.z = s->shade.light_pos.z - h->pos.z;
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&s->rotation, &vct, &h->rot);
  rotation(&s->rotation, &eye, &h->rot);
  if (h->a && h->b && h->c)
    {
      ret = (h->nappe == 1) ? _one_nappe(h, &vct, &eye) :
	(h->nappe == 2) ? _two_nappe(h, &vct, &eye) : 1;
      if (ret)
	return (-1);
      k[0] = (- h->res.b + sqrt(h->res.delta)) / (2.0 * h->res.a);
      k[1] = (- h->res.b - sqrt(h->res.delta)) / (2.0 * h->res.a);
    }
  return (return_k(k));
}
