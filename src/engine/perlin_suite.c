/*
** perlin_suite.c for rt in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 17:36:30 2016 marc brout
** Last update Sun May 22 17:37:09 2016 marc brout
*/

#include <math.h>

void		setup_r(double vec[3], int i, float *r0, float *r1)
{
  float		t;

  t = vec[i] + N;
  *r0 = t - (int)t;
  *r1 = *r0 - 1.0;
}

void		setup_b(double vec[3], int i, int *b0, int *b1)
{
  float		t;

  t = vec[i] + N;
  *b0 = ((int)t) & BM;
  *b1 = (*b0 + 1) & BM;
}

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
