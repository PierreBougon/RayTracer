/*
** tekpixel.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat Apr  9 13:49:53 2016 romain samuel
** Last update Sun Apr 24 15:15:28 2016 bougon_p
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
  t_color	*col;

  col = (t_color *)pix->pixels;
  i = pix->clipable.clip_width * pos->y + pos->x;
  col[i] = *color;
  col[i + 1] = *color;
  col[i + 2] = *color;
  i += pix->clipable.clip_width;
  col[i] = *color;
  col[i + 1] = *color;
  col[i + 2] = *color;
}
