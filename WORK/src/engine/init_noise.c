/*
** init_noise.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Apr 28 16:44:34 2016 romain samuel
** Last update Thu Apr 28 16:50:08 2016 romain samuel
*/

#include <math.h>
#include "perlin.h"

void		normalize_2d(double v[2])
{
   double	s;

   s = sqrt(v[0] * v[0] + v[1] * v[1]);
   v[0] = v[0] / s;
   v[1] = v[1] / s;
}

void		normalize_3d(double v[3])
{
   double	s;

   s = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
   v[0] = v[0] / s;
   v[1] = v[1] / s;
   v[2] = v[2] / s;
}

void	init_gradients(int i, int j)
{
  int	k;

  while (--i)
    {
      k = p[i];
      p[i] = p[j = random() % B];
      p[j] = k;
    }
  i = -1;
  while (++i < B + 2)
    {
      p[B + i] = p[i];
      g1[B + i] = g1[i];
      j = -1;
      while (++j < 2)
	g2[B + i][j] = g2[i][j];
      j = -1;
      while (++j < 3)
	g3[B + i][j] = g3[i][j];
    }
}

void	init()
{
  int	i;
  int	j;

  i  = -1;
  while (++i < B)
    {
      p[i] = i;
      g1[i] = (double)((random() % (B + B)) - B) / B;
      j = -1;
      while (++j < 2)
	g2[i][j] = (double)((random() % (B + B)) - B) / B;
      normalize_2d(g2[i]);
      j = -1;
      while (++j < 3)
	g3[i][j] = (double)((random() % (B + B)) - B) / B;
      normalize_3d(g3[i]);
    }
  init_gradients(i, j);
}
