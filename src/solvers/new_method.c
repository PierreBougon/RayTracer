/*
** new_method.c
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat May 21 20:47:34 2016 marc brout
** Last update Sat May 21 23:56:42 2016 benjamin duhieu
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
  c->root1 = sqrt((-p - sqrt(CARRE(p) - (4.0 * r))) / 2.0) -
    (c->b / (4.0 * c->a));
  c->root2 = -sqrt((-p - sqrt(CARRE(p) - (4.0 * r))) / 2.0) -
    (c->b / (4.0 * c->a));
  c->root3 = sqrt((-p + sqrt(CARRE(p) - (4.0 * r))) / 2.0) -
    (c->b / (4.0 * c->a));
  c->root4 = -sqrt((-p + sqrt(CARRE(p) - (4.0 * r))) / 2.0) -
    (c->b / (4.0 * c->a));
}

void				solver_pqr(t_4order *c)
{
  double			p;
  double			q;
  double			r;

  p = calc_p(c);
  q = calc_q(c);
  r = calc_r(c);
  printf("p : %f\n q : %f\n r : %f\n", p, q, r);
  if (q < 0.000001 && q > -0.000001)
    calc_roots(p, r, c);
  else
    q_is_not_nul(c, p, q, r);
}
