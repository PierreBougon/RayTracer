/*
** tekpixel.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat Apr  9 13:49:53 2016 romain samuel
** Last update Mon Apr 25 15:17:54 2016 bougon_p
*/

#include "raytracer.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  int		i;
  t_color	*col;

  col = (t_color *)pix->pixels;
  i = pix->clipable.clip_width * pos->y + pos->x;
  col[i] = *color;
}

void		mult_tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  int		i;
  int		i2;
  int		i3;
  int		i4;
  t_color	*col;

  col = (t_color *)pix->pixels;
  i = pix->clipable.clip_width * pos->y + pos->x;
  i2 = pix->clipable.clip_width * (pos->y + 1) + pos->x;
  i3 = pix->clipable.clip_width * (pos->y + 2) + pos->x;
  i4 = pix->clipable.clip_width * (pos->y + 3) + pos->x;
  col[i] = *color;
  col[i + 1] = *color;
  col[i + 2] = *color;
  col[i + 3] = *color;
  col[i2] = *color;
  col[i2 + 1] = *color;
  col[i2 + 2] = *color;
  col[i2 + 3] = *color;
  col[i3] = *color;
  col[i3 + 1] = *color;
  col[i3 + 2] = *color;
  col[i3 + 3] = *color;
  col[i4] = *color;
  col[i4 + 1] = *color;
  col[i4 + 2] = *color;
  col[i4 + 3] = *color;
}
