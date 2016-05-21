/*
** test.c for test in /home/duhieu_b/infographie/gfx_raytracer2/src/solvers
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue May 17 10:59:20 2016 benjamin duhieu
** Last update Sat May 21 20:57:10 2016 benjamin duhieu
*/

#include "raytracer.h"

int		main()
{
  t_3order	solv;
  t_rt		s;

  solv.root1 = -1;
  solv.root2 = -1;
  solv.root3 = -1;
  solv.a = -95;
  solv.b = 1156;
  solv.c = -12321;
  solv.d = 2400000;
  cube_order_solver(&solv);
  //  attribute_root(&s, &solv);
  printf("RES: -R1 : %f\n    -R2 : %f\n     R3 : %f\n\n", solv.root1, solv.root2, solv.root3);
  return (0);
}
