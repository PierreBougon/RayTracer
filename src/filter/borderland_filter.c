/*
** borderland_filter.c for rt2 ~/RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 14:47:32 2016 marc brout
** Last update Fri May 20 19:56:37 2016 marc brout
*/

#include "sobel.h"

static void		edge_cutter(t_bunny_pixelarray *pix,
				    const int width,
				    const int height, int cut)
{
  int			pos;
  int			value;
  int			x;
  int			y;
  t_color		*pixel;

  pixel = pix->pixels;
  y = 0;
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  pos = x + y * width;
	  value = (pixel[pos].argb[RED_CMP] +
		   pixel[pos].argb[BLUE_CMP] +
		   pixel[pos].argb[GREEN_CMP]) / 3;
	  pixel[pos].full = (value < cut) ? BACK : BORDER;
	  ++x;
	}
      ++y;
    }
}

static void		apply_borderland(t_bunny_pixelarray *src,
					 t_bunny_pixelarray *dst,
					 const int width,
					 const int height)
{
  int			pos;
  int			x;
  int			y;
  t_color		*pixsrc;
  t_color		*pixdst;

  pixsrc = src->pixels;
  pixdst = dst->pixels;
  y = 0;
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  pos = x + y * width;
	  if (pixsrc[pos].full == (unsigned int)BORDER)
	    pixdst[pos].full = BORDER;
	  ++x;
	}
      ++y;
    }
}

int			borderland(t_bunny_pixelarray **pix,
				   const int value)
{
  t_bunny_pixelarray	*sob;

  (void)value;
  if (!(sob = get_sobel(*pix)))
    return (1);
  edge_cutter(sob, (*pix)->clipable.clip_width,
	      (*pix)->clipable.clip_height, CUT);
  apply_borderland(sob, *pix, (*pix)->clipable.clip_width,
		   (*pix)->clipable.clip_height);
  bunny_delete_clipable(&sob->clipable);
  return (0);
}
