/*
** quartic_order_solver.c for quartic
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 13:53:17 2016 benjamin duhieu
** Last update Sun May 22 18:05:14 2016 benjamin duhieu
*/

#include <stdio.h>
#include "raytracer.h"

void		put_root(t_2order *x1, t_2order *x2,
			 t_4order *solv)
{
  if (x1->tab[0])
    solv->root1 = x1->root1 - (solv->b / (4.0 * solv->a));
  if (x1->tab[1])
    solv->root2 = x1->root2 - (solv->b / (4.0 * solv->a));
  if (x2->tab[0])
    solv->root3 = x2->root1 - (solv->b / (4.0 * solv->a));
  if (x2->tab[1])
    solv->root4 = x2->root2 - (solv->b / (4.0 * solv->a));
}

void		resolv_root(t_4order *solv, t_3order *res,
			    double p, double q)
{
  t_2order	x1;
  t_2order	x2;
  double	a0;
  double	b0;

  a0 = sqrt(-p + 2.0 * res->root1);
  b0 = -q / (2.0 * a0);
  x1.root1 = -1;
  x1.root2 = -1;
  x1.a = 1.0;
  x1.b = -a0;
  x1.c = res->root1 - b0;
  second_order_solver(&x1);
  x2.root1 = -1.0;
  x2.root2 = -1.0;
  x2.a = 1.0;
  x2.b = a0;
  x2.c = res->root1 + b0;
  second_order_solver(&x2);
  put_root(&x1, &x2, solv);
}

void		tri_sort3(t_3order *res)
{
  double	tmp;

  if (res->root1 < 0 && res->root2 > 0)
    {
      tmp = res->root2;
      res->root2 = res->root1;
      res->root1 = tmp;
    }
}

void		q_is_not_nul(t_4order *solv, double p,
			     double q, double r)
{
  t_3order	res;

  res.root1 = -1;
  res.root2 = -1;
  res.root3 = -1;
  res.a = 8.0;
  res.b = -4.0 * p;
  res.c = -8.0 * r;
  res.d = (4.0 * r * p) - CARRE(q);
  cube_order_solver(&res);
  tri_sort3(&res);
  resolv_root(solv, &res, p, q);
}
