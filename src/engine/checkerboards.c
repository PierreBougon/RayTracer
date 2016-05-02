/*
** checkerboards.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Apr 28 12:30:35 2016 romain samuel
** Last update Thu Apr 28 12:54:03 2016 romain samuel
*/

#include "raytracer.h"

void		stripes(t_rt *s)
{
  if (sin(M_PI / 1000) * sin((M_PI / 1000) * s->hit.simple_inter1.x) >= 0)
    s->final_color = s->hit.color1;
  else
    s->final_color = s->hit.color2;
}

void		checkerboard_2d(t_rt *s)
{
  int		jump;

  jump = ((int)(5000 + s->hit.simple_inter1.x / 1000)
	  + (int)(5000 + s->hit.simple_inter1.y / 1000)) % 2;
  if (jump == 0)
    s->final_color = s->hit.color1;
  else
    s->final_color = s->hit.color2;
}

void		planar_checkerboard(t_rt *s)
{
  int		jump;

  jump = ((int)(5000 + (s->hit.texels.x * 20000) / 1000)
	  + (int)(5000 + (s->hit.texels.y * 20000) / 1000)) % 2;
  if (jump == 0)
    s->final_color = s->hit.color1;
  else
    s->final_color = s->hit.color2;
}

void		checkerboard_3d(t_rt *s)
{
  int	jump;

  jump = ((int)(5000 + s->hit.simple_inter1.x / 1000)
	  + (int)(5000 + s->hit.simple_inter1.y / 1000)
	  + (int)(5000 + s->hit.simple_inter1.z / 1000)) % 2;
  if (jump == 0)
    s->final_color = s->hit.color1;
  else
    s->final_color = s->hit.color2;
}
