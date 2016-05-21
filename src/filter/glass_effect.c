/*
** glass_effect.c for rt2 in ~INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 16:25:22 2016 marc brout
** Last update Thu May 19 11:39:55 2016 marc brout
*/

#include <time.h>
#include "glass.h"

static void		calcul_shatter(t_bunny_pixelarray *pix,
					t_bunny_pixelarray *save,
					t_bunny_position *pos,
					int position)
{
  unsigned int		*pixels_dst;
  unsigned int		*pixels_src;
  int			x;
  int			y;
  int			newpos;

  x = (rand() % (RADIUS * 2)) - RADIUS;
  y = (rand() % (RADIUS * 2)) - RADIUS;
  pixels_dst = save->pixels;
  pixels_src = pix->pixels;
  if ((pos->x + x) >= 0 && (pos->x + x) < pix->C_W - 1 &&
      (pos->y + y) >= 0 && (pos->y + y) < pix->C_H - 1)
    {
      newpos = pos->x + x + ((pos->y + y) * pix->clipable.clip_width);
      pixels_dst[position] = pixels_src[newpos];
    }
  else
    pixels_dst[position] = pixels_src[position];
}

void			apply_shatter(t_bunny_pixelarray *pix,
				      t_bunny_pixelarray *save,
				      const int width,
				      const int height)
{
  int			position;
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < height)
    {
      pos.x = 0;
      while (pos.x < width)
	{
	  position = pos.x + pos.y * width;
	  calcul_shatter(pix, save, &pos, position);
	  ++pos.x;
	}
      ++pos.y;
    }
}

static void		fill_median(t_bunny_pixelarray *src,
				    t_bunny_position *pos,
				    unsigned int median[SIZE],
				    const int width)
{
  t_color		*pixels;
  int			position;
  int			y;
  int			x;

  y = -1;
  pixels = src->pixels;
  while (++y < RACSIZE)
    {
      x = -1;
      while (++x < RACSIZE)
	{
	  if (pos->x + x >= RACSIZE / 2 && pos->x +
	      x < width - RACSIZE / 2 && pos->y + y >= RACSIZE / 2 &&
	      pos->y + y < src->C_H - RACSIZE / 2)
	    {
	      position = pos->x + x - (RACSIZE / 2) +
		((pos->y + y - RACSIZE / 2) * width);
	      median[x + y * RACSIZE] = pixels[position].full;
	    }
	  else
	    median[x + y * RACSIZE] = BLACK;
	}
    }
}

static void		tri_median(unsigned int median[SIZE])
{
  unsigned int		min;
  int			i;
  int			j;

  i = 0;
  while (i < SIZE / 2 + 1)
    {
      j = 0;
      min = median[i];
      while (j < SIZE)
	{
	  if (median[j]
	      < min)
	    {
	      min = median[j];
	      median[j] = median[i];
	      median[i] = min;
	      break;
	    }
	  ++j;
	}
      ++i;
    }
}

void			apply_median(t_bunny_pixelarray *src,
				     t_bunny_pixelarray *dst,
				     const int width,
				     const int height)
{
  unsigned int		median[SIZE];
  unsigned int		*pixels;
  t_bunny_position	pos;

  pos.y = 0;
  pixels = dst->pixels;
  while (pos.y < height)
    {
      pos.x = 0;
      while (pos.x < width)
	{
	  fill_median(src, &pos, median, width);
	  tri_median(median);
	  pixels[pos.x + pos.y * width] = median[SIZE / 2];
	  ++pos.x;
	}
      ++pos.y;
    }
}
