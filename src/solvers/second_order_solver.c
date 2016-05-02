/*
** second_order_solver.c for raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 13 13:45:54 2016 marc brout
** Last update Wed Apr 13 13:59:59 2016 marc brout
*/

void		second_order_solver(t_2order *res)
{
  res->delta = (res->b * res->b) - (4 * res->a * res->c);
  if (!delta)
    res->root1 = -res->b / (2 * res->a);
  else if (delta > 0)
    {
      res->root1 = (-res->b + sqrt(res->delta)) / (2 *res->a);
      res->root2 = (-res->b - sqrt(res->delta)) / (2 *res->a);
    }
}
