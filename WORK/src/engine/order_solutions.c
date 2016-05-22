/*
** order_solutions.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May 18 20:07:00 2016 romain samuel
** Last update Wed May 18 20:21:13 2016 romain samuel
*/

#include "raytracer.h"

int		order_solutions(t_rt *s)
{
  double	temp1;
  t_acc		temp2;

  if (s->hit.k1 < 0.000001 && s->hit.k2 < 0.000001)
    return (-1);
  if ((s->hit.k2 < s->hit.k1 && s->hit.k2 > 0.000001) ||
      (s->hit.k1 < 0.000001 && s->hit.k2 > 0.000001))
    {
      temp1 = s->hit.k2;
      s->hit.k2 = s->hit.k1;
      s->hit.k1 = temp1;
      temp2 = s->hit.simple_inter2;
      s->hit.simple_inter2 = s->hit.simple_inter1;
      s->hit.simple_inter1 = temp2;
      temp2 = s->hit.norm2;
      s->hit.norm2 = s->hit.norm1;
      s->hit.norm1 = temp2;
    }
  return (0);
}
