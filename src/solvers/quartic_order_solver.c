/*
** quartic_order_solver.c for quartic
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 13:53:17 2016 benjamin duhieu
** Last update Wed May  4 16:40:57 2016 benjamin duhieu
*/

#include "raytracer.h"

double		minus_resolv3(double a, double b, double c, double d)
{
  t_3order	res;
  int		chk;

  res.a = a;
  res.b = b;
  res.c = c;
  res.d = d;
  if ((chk = cube_order_solver(&res)) == 1)
    return (res.root1);
  else if (chk == 3)
    {
      if (res.root1 >= res.root2 && res.root1 >= res.root3)
	return (res.root1);
      else if (res.root2 >= res.root3)
	return (res.root2);
      else
	return (res.root3);
    }
  return (0);
}

void		select4(double *step, t_4order *solv)
{
  t_2order	sec;
  int		chk;

  sec.a = 1;
  sec.b = step[1];
  sec.c = step[0] + step[2];
  if (!(chk = second_order_solver(&sec)))
    solv->root1 = sec.root1 - solv->b / 4.0;
  else if (chk == 1)
    {
      solv->root1 = sec.root1 - solv->b / 4.0;
      solv->root2 = sec.root2 - solv->b / 4.0;
    }
  sec.a = 1;
  sec.b = -step[1];
  sec.c = step[0] - step[2];
  if (!(chk = second_order_solver(&sec)))
    solv->root3 = sec.root1 - solv->b / 4.0;
  else if (chk == 1)
    {
      solv->root3 = sec.root1 - solv->b / 4.0;
      solv->root4 = sec.root2 - solv->b / 4.0;
    }
}

void		resolv_4_degres(t_4order *solv)
{
  double	tmp[3];
  double	step[3];

  solv->b = solv->b / solv->a;
  solv->c = solv->c / solv->a;
  solv->d = solv->d / solv->a;
  solv->e = solv->e / solv->a;
  tmp[0] = -(3.0 / 8.0) * CARRE(solv->b) + solv->c;
  tmp[1] = ((1.0 / 8.0) * CUBE(solv->b)) -
    ((1.0 / 2.0) * solv->b * solv->c) + solv->d;
  tmp[2] = (-(3.0 / 256.0) * QUARTIC(solv->b)) +
    ((1.0 / 16.0) * CARRE(solv->b) * solv->c) -
    ((1.0 / 4.0) * solv->b * solv->d) + solv->e;
  step[0] = minus_resolv3(1, -(tmp[0] / 2), -tmp[2],
			  (1.0 / 2.0) * tmp[0] * tmp[2]) -
    ((1.0 / 8.0) * CARRE(tmp[1]));
  step[2] = sqrt(CARRE(step[0]) - tmp[2]);
  step[1] = tmp[1] / (-2 * step[2]);
  select4(step, solv);
}
