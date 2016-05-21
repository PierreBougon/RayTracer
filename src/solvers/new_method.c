/*
** new_method.c
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat May 21 20:47:34 2016 marc brout
** Last update Sat May 21 22:21:36 2016 marc brout
*/

#include "raytracer.h"

static inline double		calc_p(t_4order *c)
{
  return ((-3.0 * CARRE(c->b)) / (8.0 * CARRE(c->a)) + c->c / c->a);
}

static inline double		calc_q(t_4order *c)
{
  return ((CUBE(c->b) / (8.0 * CUBE(c->a))) -
	  ((c->b * c->c) / (2.0 * (CARRE(c->a)))) +
	  (c->d / c->a));
}

static inline double		calc_r(t_4order *c)
{
  return ((-3.0 * QUARTIC((c->b / 4.0) / c->a)) +
	  (c->c * (CARRE(c->b / 4.0) / CUBE(c->a))) -
	  (((c->b * c->d) * (1.0 / 4.0)) / CARRE(c->a)) +
	  (c->e / c->a));
}

static inline void		calc_roots(const double p,
					   const double r, t_4order *c)
{
  double			rac;
  double			rac1;
  double			rac2;

  rac = sqrt((CARRE(p) / 4.0) - r);
  rac1 = sqrt((p / 2.0) + rac);
  rac2 = sqrt((p / 2.0) - rac);
  c->root1 = rac1;
  c->root2 = -rac1;
  c->root3 = rac2;
  c->root4 = -rac2;
}

void				solver_pqr(t_4order *c)
{
  double			p;
  double			q;
  double			r;

  p = calc_p(c);
  q = calc_q(c);
  r = calc_r(c);
  if (q < 0.000001 && q > -0.000001)
    calc_roots(p, r, c);
  else
    q_is_not_null(c, p, q, r);
}
