/*
** oil_init.c for  in INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 15:00:21 2016 marc brout
** Last update Wed May 18 15:02:53 2016 marc brout
*/

#include "oil_effect.h"

void			init_oil(t_oil *oil, const unsigned int size)
{
  unsigned int		i;

  i = 0;
  while (i < size)
    {
      oil->intensity_count[i] = 0;
      oil->r_avg[i] = 0;
      oil->b_avg[i] = 0;
      oil->g_avg[i] = 0;
      ++i;
    }
}
