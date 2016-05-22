/*
** shadow_para.c for rt2 in ~/INFOGRAPHIE/gfx_raytracer2/src/engine
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 14:51:29 2016 marc brout
** Last update Sun May 22 15:22:53 2016 marc brout
*/

#include "raytracer.h"

static int	_parab_ellip(t_parab *p, t_acc *vct, t_acc *eye)
{
  p->res.a = (CARRE(vct->x) / CARRE(p->a)) +
    (CARRE(vct->y) / CARRE(p->b));
  p->res.b = 2 * (((vct->x * eye->x) / CARRE(p->a)) +
	       ((vct->y * eye->y) / CARRE(p->b))) -
    (vct->z / p->c);
  p->res.c = (CARRE(eye->x) / CARRE(p->a)) +
    (CARRE(eye->y) / CARRE(p->b)) -
    (eye->z / p->c);
  if ((p->res.delta = CARRE(p->res.b) - 4.0 *
       p->res.a * p->res.c) < 0.0001)
    return (1);
  return (0);
}

static int	_parab_hyper(t_parab *p, t_acc *vct, t_acc *eye)
{
  p->res.a = (CARRE(vct->x) / CARRE(p->a)) -
    (CARRE(vct->y) / CARRE(p->b));
  p->res.b = 2 * (((vct->x * eye->x) / CARRE(p->a)) -
		  ((vct->y * eye->y) / CARRE(p->b))) -
    (vct->z / p->c);
  p->res.c = (CARRE(eye->x) / CARRE(p->a)) -
    (CARRE(eye->y) / CARRE(p->b)) -
    (eye->z / p->c);
  if ((p->res.delta = CARRE(p->res.b) - 4.0 * p->res.a * p->res.c)
      < 0.0001)
    return (1);
  return (0);
}

double		shadow_inter_para(t_rt *s, t_parab *p)
{
  t_acc		eye;
  t_acc		vct;
  int		ret;
  double	k[2];

  eye.x = s->shade.light_pos.x - p->pos.x;
  eye.y = s->shade.light_pos.y - p->pos.y;
  eye.z = s->shade.light_pos.z - p->pos.z;
  vct = set_pos(s->shade.vct.x, s->shade.vct.y, s->shade.vct.z);
  rotation(&s->rotation, &vct, &p->rot);
  rotation(&s->rotation, &eye, &p->rot);
  if (p->a && p->b)
    {
      ret = (p->form == 1) ? _parab_ellip(p, &vct, &eye) :
	(p->form == 2) ? _parab_hyper(p, &vct, &eye) : -1;
      if (ret)
	return (-1);
      k[0] = (- p->res.b + sqrt(p->res.delta)) / (2.0 * p->res.a);
      k[1] = (- p->res.b - sqrt(p->res.delta)) / (2.0 * p->res.a);
    }
  return (return_k(k));
}
