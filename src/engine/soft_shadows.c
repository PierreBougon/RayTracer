/*
** soft_shadows.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 18:52:17 2016 romain samuel
** Last update Sun May 22 21:43:27 2016 benjamin duhieu
*/

#include "raytracer.h"

double		get_soft_intensity(t_rt *s, double *tab)
{
  double	i;
  int		j;

  j = 0;
  i = 0;
  while (j < s->opt.nb_rays_ss)
    {
      i += tab[j];
      j++;
    }
  i = i / (double)s->opt.nb_rays_ss;
  return (i);
}
