/*
** sobel_filter.c for ~/RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon May 16 17:57:01 2016 marc brout
** Last update Wed May 18 14:56:03 2016 marc brout
*/

#include <stdio.h>
#include <math.h>
#include "lapin.h"
#include "sobel.h"

static void		calc_sobel(t_color *pix,
				   t_sobel *sobel,
				   int x_kernel[3][3],
				   int y_kernel[3][3])
{
  int			pos;
  int			x;
  int			y;

  y = 0;
  while (y < 3)
    {
      x = 0;
      while (x < 3)
	{
	  pos = sobel->pos.x + x - 1 + ((sobel->pos.y + y - 1) *
					sobel->width);
	  sobel->x_red += x_kernel[y][x] * pix[pos].argb[RED_CMP];
	  sobel->x_blue += x_kernel[y][x] * pix[pos].argb[BLUE_CMP];
	  sobel->x_green += x_kernel[y][x] * pix[pos].argb[GREEN_CMP];
	  sobel->y_red += y_kernel[y][x] * pix[pos].argb[RED_CMP];
	  sobel->y_blue += y_kernel[y][x] * pix[pos].argb[BLUE_CMP];
	  sobel->y_green += y_kernel[y][x] * pix[pos].argb[GREEN_CMP];
	  ++x;
	}
      ++y;
    }
  sobel->x_red = sqrt(CARRE(sobel->x_red) + CARRE(sobel->y_red));
  sobel->x_blue = sqrt(CARRE(sobel->x_blue) + CARRE(sobel->y_blue));
  sobel->x_green = sqrt(CARRE(sobel->x_green) + CARRE(sobel->y_green));
}

static void		apply_sobel(t_sobel *sobel,
				    t_bunny_pixelarray *pixel)
{
  t_color		*pix;
  int			pos;

  pix = pixel->pixels;
  pos = sobel->pos.x + sobel->pos.y * sobel->width;
  sobel->x_red = (sobel->x_red < 0) ? 0 :
    (sobel->x_red > 255) ? 255 : sobel->x_red;
  sobel->x_blue = (sobel->x_blue < 0) ? 0 :
    (sobel->x_blue > 255) ? 255 : sobel->x_blue;
  sobel->x_green = (sobel->x_green < 0) ? 0 :
    (sobel->x_green > 255) ? 255 : sobel->x_green;
  pix[pos].argb[RED_CMP] = sobel->x_red;
  pix[pos].argb[BLUE_CMP] = sobel->x_blue;
  pix[pos].argb[GREEN_CMP] = sobel->x_green;
}

static void		sobel_filter(t_bunny_pixelarray *pix,
				     t_bunny_pixelarray *save,
				     int x_kernel[3][3],
				     int y_kernel[3][3])
{
  t_sobel		sobel;

  sobel.pos.y = 0;
  sobel.width = pix->clipable.clip_width;
  sobel.height = pix->clipable.clip_height;
  while (sobel.pos.y < sobel.height)
    {
      sobel.pos.x = 0;
      while (sobel.pos.x < sobel.width)
	{
	  init_sobel(&sobel);
	  if (sobel.pos.x && sobel.pos.y &&
	      sobel.pos.x < sobel.width - 1 &&
	      sobel.pos.y < sobel.height - 1)
	    calc_sobel(pix->pixels, &sobel, x_kernel, y_kernel);
	  apply_sobel(&sobel, save);
	  ++sobel.pos.x;
	}
      ++sobel.pos.y;
    }
}

t_bunny_pixelarray	*get_sobel(t_bunny_pixelarray *pix)
{
  t_bunny_pixelarray	*save;
  int			x_kernel[3][3];
  int			y_kernel[3][3];

  if (!(save = bunny_new_pixelarray(pix->clipable.clip_width,
				    pix->clipable.clip_height)))
    return (NULL);
  init_kernels(x_kernel, y_kernel);
  sobel_filter(pix, save, x_kernel, y_kernel);
  return (save);
}

int			sobel(t_bunny_pixelarray **pix)
{
  t_bunny_pixelarray	*save;

  if (!(save = get_sobel(*pix)))
    return (1);
  bunny_delete_clipable(&(*pix)->clipable);
  *pix = save;
  return (0);
}
