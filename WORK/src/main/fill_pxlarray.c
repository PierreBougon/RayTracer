/*
** fill_pxlarray.c for FILL PIXEL ARRAY in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 16 18:45:46 2016 bougon_p
** Last update Wed Apr 20 17:00:57 2016 bougon_p
*/

#include "raytracer.h"

int			fill_next_lines(t_bunny_pixelarray *pxar,
					unsigned int color,
					int line, int nb_line)
{
  int			i;
  int			j;
  t_color		col;
  t_bunny_position	pxpos;

  col.full = color;
  i = line - 1;
  while (++i < pxar->clipable.clip_width
	 && i < line + nb_line)
    {
      j = -1;
      while (++j < pxar->clipable.clip_height)
	{
	  pxpos.x = i;
	  pxpos.y = j;
	  tekpixel(pxar, &pxpos, &col);
	}
    }
  return (i);
}

void			fill_pxlarray(t_bunny_pixelarray *pxar,
				      unsigned int color)
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
