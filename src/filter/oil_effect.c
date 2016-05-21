/*
** sobel_filter.c for ~/RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon May 16 17:57:01 2016 marc brout
** Last update Wed May 18 15:02:51 2016 marc brout
*/

#include "oil_effect.h"

static void		get_color(t_bunny_pixelarray *pix,
				  const int x, const int y,
				  t_oil *oil)
{
  int			pos;
  t_color		*color;

  color = pix->pixels;
  pos = x + y * pix->clipable.clip_width;
  oil->red = color[pos].argb[RED_CMP];
  oil->blue = color[pos].argb[BLUE_CMP];
  oil->green = color[pos].argb[GREEN_CMP];
}

static void		apply_normalize_oil(t_bunny_pixelarray *save,
					    t_oil *oil, int size)
{
  t_color		*pixels;
  int			pos;
  int			max_i;
  int			max_count;
  int			i;

  i = 0;
  max_i = 0;
  max_count = oil->intensity_count[0];
  pixels = save->pixels;
  while (i < size)
    {
      if (oil->intensity_count[i] > max_count)
	{
	  max_count = oil->intensity_count[i];
	  max_i = i;
	}
      ++i;
    }
  pos = oil->pos.x + oil->pos.y * save->clipable.clip_width;
  pixels[pos].argb[RED_CMP] = oil->r_avg[max_i] / max_count;
  pixels[pos].argb[BLUE_CMP] = oil->b_avg[max_i] / max_count;
  pixels[pos].argb[GREEN_CMP] = oil->g_avg[max_i] / max_count;
}

static void		calculate_avg(t_bunny_pixelarray *pix,
				      t_oil *oil, const int x,
				      const int y)
{
  int			cur;
  int			i;
  int			j;

  j = -RADIUS - 1;
  while (++j <= RADIUS)
    {
      i = -RADIUS - 1;
      while (++i <= RADIUS)
	if (x + i >= 0 && x + i <= pix->clipable.clip_width &&
	    y + j >= 0 && y + j <= pix->clipable.clip_height)
	  {
	    get_color(pix, x + i, y + j, oil);
	    cur = (int)((((oil->red + oil->blue + oil->green) / 3.0) *
			 (double)LEVEL) / 255.0);
	    oil->intensity_count[cur] += 1;
	    oil->r_avg[cur] += oil->red;
	    oil->b_avg[cur] += oil->blue;
	    oil->g_avg[cur] += oil->green;
	}
    }
}

static void		calculate_oil(t_bunny_pixelarray *pix,
				      t_bunny_pixelarray *save,
				      t_oil *oil)
{
  int			y;
  int			x;
  int			width;
  int			height;

  y = 0;
  width = pix->clipable.clip_width;
  height = pix->clipable.clip_height;
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  init_oil(oil, LEVEL + 1);
	  calculate_avg(pix, oil, x, y);
	  apply_normalize_oil(save, oil, LEVEL + 1);
	  ++x;
	}
      ++y;
    }
}

int			oil(t_bunny_pixelarray **pix)
{
  t_bunny_pixelarray	*save;
  t_oil			oil;

  if (!(save = bunny_new_pixelarray((*pix)->clipable.clip_width,
				    (*pix)->clipable.clip_height)))
    return (1);
  calculate_oil(*pix, save, &oil);
  bunny_delete_clipable(&(*pix)->clipable);
  *pix = save;
  return (0);
}