/*
** init_shade.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 12:47:21 2016 romain samuel
** Last update Tue Apr 19 12:48:25 2016 romain samuel
*/

#include "raytracer.h"

int		init_soft_shadow(t_rt *s)
{
  int		rd;

  rd = rand() % 1000;
  s->shade.x_diff = rd - 500;
  rd = rand() % 1000;
  s->shade.y_diff = rd - 500;
  rd = rand() % 1000;
  s->shade.z_diff = rd - 500;
  return (0);
}

void		init_lum(t_rt *s, t_acc *vct, t_acc eye, t_light *light)
{
  s->shade.inter.x = eye.x + s->hit.k1 * vct->x;
  s->shade.inter.y = eye.y + s->hit.k1 * vct->y;
  s->shade.inter.z = eye.z + s->hit.k1 * vct->z;
  s->shade.light_pos.x = light->pos.x/* + s->shade.x_diff*/;
  s->shade.light_pos.y = light->pos.y/* + s->shade.y_diff*/;
  s->shade.light_pos.z = light->pos.z/* + s->shade.z_diff*/;
  s->shade.vct.x = s->shade.inter.x - (double)s->shade.light_pos.x;
  s->shade.vct.y = s->shade.inter.y - (double)s->shade.light_pos.y;
  s->shade.vct.z = s->shade.inter.z - (double)s->shade.light_pos.z;
}

void		init_itab(double itab[1])
{
  int		i;

  i = 0;
  while (i < 1)
    {
      itab[i] = 0.0;
      i++;
    }
}
