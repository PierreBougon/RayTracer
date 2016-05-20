/*
** second_order_solver.c for raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 13 13:45:54 2016 marc brout
** Last update Fri May 20 12:42:24 2016 benjamin duhieu
*/

#include "raytracer.h"

int		second_order_solver(t_2order *res)
{
  res->delta = (res->b * res->b) - (4 * res->a * res->c);
  if (!res->delta)
    {
      res->root1 = -res->b / (2 * res->a);
      /* printf("\n<<<<<delta : %f && a : %f && b : %f && c : %f>>>>>>\n", res->delta, res->a, res->b, res->c); */
      /* printf("s->k1 : %f && s->k2 : %f\n", res->root1, res->root2); */

      return (0);
    }
  if (res->delta > 0)
    {
      res->root1 = (-res->b + sqrt(res->delta)) / (2 * res->a);
      res->root2 = (-res->b - sqrt(res->delta)) / (2 * res->a);
      /* printf("\n<<<<<delta : %f && a : %f && b : %f && c : %f>>>>>>\n", res->delta, res->a, res->b, res->c); */
      /* printf("s->k1 : %f && s->k2 : %f\n", res->root1, res->root2); */
      return (1);
    }
  /* if (res->root1 >= 0 || res->root2 >= 0) */
  /*   { */
    /* } */
  return (-1);
}
