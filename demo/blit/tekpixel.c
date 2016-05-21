/*
** tekpixel.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat Apr  9 13:49:53 2016 romain samuel
** Last update Sat Apr  9 13:51:41 2016 romain samuel
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
