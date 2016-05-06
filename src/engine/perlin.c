/*
** perlin.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed Apr 27 18:35:44 2016 romain samuel
** Last update Thu May  5 19:30:49 2016 romain samuel
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "perlin.h"

static int p[B + B + 2];
static double g3[B + B + 2][3];
static double g2[B + B + 2][2];
static double g1[B + B + 2];
static int start = 1;

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

double		noise_end(t_noise_3d noise)
{
  noise.q = g3[noise.b00 + noise.bz0] ;
  noise.u = at3(noise.rx0, noise.ry0, noise.rz0, noise.q);
  noise.q = g3[noise.b10 + noise.bz0] ;
  noise.v = at3(noise.rx1, noise.ry0, noise.rz0, noise.q);
  noise.a = lerp(noise.t, noise.u, noise.v);
  noise.q = g3[noise.b01 + noise.bz0] ;
  noise.u = at3(noise.rx0, noise.ry1, noise.rz0, noise.q);
  noise.q = g3[noise.b11 + noise.bz0] ;
  noise.v = at3(noise.rx1, noise.ry1, noise.rz0, noise.q);
  noise.b = lerp(noise.t, noise.u, noise.v);
  noise.c = lerp(noise.sy, noise.a, noise.b);
  noise.q = g3[noise.b00 + noise.bz1] ;
  noise.u = at3(noise.rx0, noise.ry0, noise.rz1, noise.q);
  noise.q = g3[noise.b10 + noise.bz1] ;
  noise.v = at3(noise.rx1, noise.ry0, noise.rz1, noise.q);
  noise.a = lerp(noise.t, noise.u, noise.v);
  noise.q = g3[noise.b01 + noise.bz1] ;
  noise.u = at3(noise.rx0, noise.ry1, noise.rz1, noise.q);
  noise.q = g3[noise.b11 + noise.bz1] ;
  noise.v = at3(noise.rx1, noise.ry1, noise.rz1, noise.q);
  noise.b = lerp(noise.t, noise.u, noise.v);
  noise.d = lerp(noise.sy, noise.a, noise.b);
  return (lerp(noise.sz, noise.c, noise.d));
}

double		noise_3d(double vec[3])
{
  t_noise_3d	noise;

  if (start)
    {
      start = 0;
      init();
    }
  setup_b(vec, 0, &noise.bx0, &noise.bx1);
  setup_b(vec, 1, &noise.by0, &noise.by1);
  setup_b(vec, 2, &noise.bz0, &noise.bz1);
  setup_r(vec, 0, &noise.rx0, &noise.rx1);
  setup_r(vec, 1, &noise.ry0, &noise.ry1);
  setup_r(vec, 2, &noise.rz0, &noise.rz1);
  noise.i = p[noise.bx0];
  noise.j = p[noise.bx1];
  noise.b00 = p[noise.i + noise.by0];
  noise.b10 = p[noise.j + noise.by0];
  noise.b01 = p[noise.i + noise.by1];
  noise.b11 = p[noise.j + noise.by1];
  noise.t = s_curve(noise.rx0);
  noise.sy = s_curve(noise.ry0);
  noise.sz = s_curve(noise.rz0);
  return (noise_end(noise));
}

double		perlin_noise_3d(double p[3], double alpha, double beta, int n)
{
   int		i;
   double	val;
   double	sum;
   double	scale;

   scale = 1;
   sum = 0;
   i = -1;
   while (++i<n)
     {
       val = noise_3d(p);
       sum += val / scale;
       scale *= alpha;
       p[0] *= beta;
       p[1] *= beta;
       p[2] *= beta;
     }
   return (sum);
}
