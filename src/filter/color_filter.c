/*
** color_filter.c in ~RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu May 19 20:42:27 2016 marc brout
** Last update Sat May 21 15:42:28 2016 marc brout
*/

#include "lapin.h"

static void	apply_color(t_bunny_pixelarray *pix,
			    const unsigned int _color,
			    const int pos,
			    const double opacity)
{
  t_color	color;
  t_color	*pixels;
  double	value;
  double	op;

  op = 1.0 - opacity;
  color.full = _color;
  pixels = pix->pixels;
  value = (double)pixels[pos].argb[RED_CMP] * op +
    (double)color.argb[RED_CMP] * opacity;
  pixels[pos].argb[RED_CMP] = (value > 255) ? 255 : value;
  value = (double)pixels[pos].argb[BLUE_CMP] * op +
    (double)color.argb[BLUE_CMP] * opacity;
  pixels[pos].argb[BLUE_CMP] = (value > 255) ? 255 : value;
  value = (double)pixels[pos].argb[GREEN_CMP] * op +
    (double)color.argb[GREEN_CMP] * opacity;
  pixels[pos].argb[GREEN_CMP] = (value > 255) ? 255 : value;
}

int		color(t_bunny_pixelarray **pix,
		      const int color)
{
  int		x;
  int		y;
  int		pos;

  y = 0;
  while (y < (*pix)->clipable.clip_height)
    {
      x = 0;
      while (x < (*pix)->clipable.clip_width)
	{
	  pos = x + y * (*pix)->clipable.clip_width;
	  apply_color(*pix, (unsigned int)color, pos, 0.2);
	  ++x;
	}
      ++y;
    }
  return (0);
}
