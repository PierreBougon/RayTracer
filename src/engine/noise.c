/*
** noise.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Apr 28 13:03:16 2016 romain samuel
** Last update Thu Apr 28 16:47:17 2016 romain samuel
*/

#include "perlin.h"

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
