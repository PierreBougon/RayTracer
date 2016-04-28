/*
** setup_noise.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Apr 28 16:45:54 2016 romain samuel
** Last update Thu Apr 28 16:47:19 2016 romain samuel
*/

#include "perlin.h"

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
