/*
** tekpixel.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat Apr  9 13:49:53 2016 romain samuel
** Last update Sat May 21 19:31:34 2016 bougon_p
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
			      t_color *color, int n)
{
  t_bunny_position	apos;
  t_bunny_position	dpos;

  apos.y = -1;
  while (++apos.y < n)
    {
      apos.x = -1;
      while (++apos.x < n)
	{
	  dpos.x = pos->x + apos.x;
	  dpos.y = pos->y + apos.y;
	  if (dpos.x < pix->clipable.clip_width
	      && dpos.y < pix->clipable.clip_height)
	  tekpixel(pix, &dpos, color);
	}
    }
}

void		pad_tekpixelx(t_bunny_pixelarray *pix,
			      t_bunny_position *pos,
			      t_color *color)
{
  t_bunny_position	apos;
  t_bunny_position	dpos;

  apos.y = -1;
  while (++apos.y < 4)
    {
      apos.x = -1;
      while (++apos.x < pix->clipable.clip_width)
	{
	  dpos.x = pos->x + apos.x;
	  dpos.y = pos->y + apos.y;
	  tekpixel(pix, &dpos, color);
	}
    }
}
