/*
** fill_pxlarray.c for FILL PIXEL ARRAY in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 16 18:45:46 2016 bougon_p
** Last update Sat Apr 16 18:57:22 2016 bougon_p
*/

#include "raytracer.h"

void			fill_pxlarray(t_bunny_pixelarray *pxar, unsigned int color)
{
  int			i;
  int			j;
  t_color		col;
  t_bunny_position	pxpos;

  col.full = color;
  j = -1;
  while (++j < pxar->clipable.clip_height)
    {
      i = -1;
      while (++i < pxar->clipable.clip_width)
	{
	  pxpos.x = i;
	  pxpos.y = j;
	  tekpixel(pxar, &pxpos, &col);
	}
    }
}
