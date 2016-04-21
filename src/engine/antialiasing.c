/*
** antialiasing.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 17:43:34 2016 romain samuel
** Last update Wed Apr 13 23:27:54 2016 bougon_p
*/

#include "raytracer.h"

t_color			melt_colors(t_rt *s, t_color *color)
{
  int			i;
  unsigned int		r;
  unsigned int		g;
  unsigned int		b;
  t_color		final_color;

  i = 0;
  r = 0;
  g = 0;
  b = 0;
  while (i < s->opt.aa)
    {
      r += (color[i].full & 0xFF);
      g += ((color[i].full >> 8) & 0xFF);
      b += ((color[i].full >> 16) & 0xFF);
      i++;
    }
  r = r / s->opt.aa;
  g = g / s->opt.aa;
  b = b / s->opt.aa;
  final_color.full = 0xFF000000 + (b << 16) + (g << 8) + r;
  return (final_color);
}

t_color			antialiasing(t_rt *s,
				     t_bunny_position *pos,
				     t_acc *vct,
				     t_color *color)
{
  int			i;
  int			j;
  int			x;
  int			k;

  i = -1;
  k = 0;
  x = sqrt(s->opt.aa);
  while (++i < x)
    {
      j = -1;
      while (++j < x)
	{
	  vct->x = ((double)s->width / 2.0)
	    - ((double)pos->x + (1.0 / (double)x) * j);
	  vct->y = ((double)s->height / 2.0)
	    - ((double)pos->y + (1.0 / (double)x) * i);
	  vct->z = 1000;
	  rotation(vct, &s->eye.rot);
	  color[k++] = display_objects(s, vct, s->eye.pos, 0);
	}
    }
  color[0] = melt_colors(s, color);
  return (color[0]);
}
