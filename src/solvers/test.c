/*
** test.c for test in /home/duhieu_b/infographie/gfx_raytracer2/src/solvers
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue May 17 10:59:20 2016 benjamin duhieu
** Last update Sat May 21 22:01:24 2016 benjamin duhieu
*/

#include "raytracer.h"

int		main()
{
  t_4order	solv;
  t_rt		s;

  solv.root1 = -1;
  solv.root2 = -1;
  solv.root3 = -1;
  solv.root4 = -1;
  solv.a = -2;
  solv.b = -2;
  solv.c = 1;
  solv.d = 5;
  solv.e = 5;
  solver_pqr(&solv);
  attribute_root(&s, &solv);
  printf("RES: -R1 : %f\n    -R2 : %f\n     R3 : %f\n      R4 : %f\n", s.hit.k1, s.hit.k2, s.hit.k3, s.hit.k4);
  return (0);
}
