/*
** cube_order_solver.c for cube_solver
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue May  3 11:21:24 2016 benjamin duhieu
** Last update Wed May  4 16:34:59 2016 benjamin duhieu
*/

#include <math.h>
#include "raytracer.h"

void		three_root(double r, double q, t_3order *solv)
{
  double	s;
  double	w;
  double	delta1;

  delta1 = r / pow(q, 1.5);
  w = acos(delta1) / 3.0;
  s = -2.0 * sqrt(q);
  solv->root1 = (s * cos(w + (2.0 * M_PI * (0.0 / 3.0)))) - solv->b / 3.0;
  solv->root2 = (s * cos(w + (2.0 * M_PI * (1.0 / 3.0)))) - solv->b / 3.0;
  solv->root3 = (s * cos(w + (2.0 * M_PI * (2.0 / 3.0)))) - solv->b / 3.0;
}

void		one_root(double delta, double r, double q, t_3order *solv)
{
  double	s;

  s = pow(sqrt(-delta) + ABS(r), 1.0 / 3.0);
  if (r < 0)
    solv->root1 = s + (q / s) - (solv->b / 3.0);
  else
    solv->root1 = -s - (q / s) - (solv->b / 3.0);
}

int		cube_order_solver(t_3order *solv)
{
  double	q;
  double	r;
  double	delta;

  solv->b = solv->b / solv->a;
  solv->c = solv->c / solv->a;
  solv->d = solv->d / solv->a;
  q = (CARRE(solv->b) - 3.0 * solv->c) / 9.0;
  r = ((solv->b * (CARRE(solv->b) - 4.5 * solv->c)) + 13.5 * solv->d)
    / 27.0;
  delta = CUBE(q) - CARRE(r);
  if (delta <= 0)
    {
      one_root(delta, r, q, solv);
      return (1);
    }
  else
    {
      three_root(r, q, solv);
      return (3);
    }
  return (0);
}
