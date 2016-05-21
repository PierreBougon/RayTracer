/*
** boxfiltering.c ~/RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu May 19 22:34:51 2016 marc brout
** Last update Sat May 21 15:42:35 2016 marc brout
*/

#include "box_filtering.h"

static void		init_box(int box[9], const int width)
{
  box[0] = -width - 1;
  box[1] = -width;
  box[2] = -width + 1;
  box[3] = -1;
  box[4] = 0;
  box[5] = 1;
  box[6] = width - 1;
  box[7] = width;
  box[8] = width + 1;
}

static double		box_divisor(int kernel[9])
{
  return (kernel[0] + kernel[1] + kernel[2] +
	  kernel[3] + kernel[4] + kernel[5] +
	  kernel[6] + kernel[7] + kernel[8]);
}

static void		calculate_box(t_boxe *box,
				      const int pos,
				      t_bunny_pixelarray *pix)
{
  t_color		*pixels;
  int			i;

  i = 0;
  pixels = pix->pixels;
  box->red = box->blue = box->green = 0;
  while (i < 9)
    {
      box->red += pixels[pos + box->box[i]].argb[RED_CMP] *
	(double)box->kernel[i];
      box->blue += pixels[pos + box->box[i]].argb[BLUE_CMP] *
	(double)box->kernel[i];
      box->green += pixels[pos + box->box[i]].argb[GREEN_CMP] *
	(double)box->kernel[i];
      ++i;
    }
  box->red = ((box->red = box->red / box->div) > 255) ? 255 :
    (box->red < 0) ? 0 : box->red;
  box->blue = ((box->blue = box->blue / box->div) > 255) ? 255 :
    (box->blue < 0) ? 0 : box->blue;
  box->green = ((box->green = box->green / box->div) > 255) ? 255 :
    (box->green < 0) ? 0 : box->green;
}

static void		apply_box_filter(t_bunny_pixelarray *pix,
					 t_bunny_pixelarray *save,
					 t_boxe *box)
{
  int			x;
  int			y;
  int			pos;
  unsigned int		*pixels;
  t_color		*savpix;

  pixels = pix->pixels;
  savpix = save->pixels;
  y = -1;
  while (++y < pix->CH && (x = -1))
    {
      while (++x < pix->CW)
	{
	  pos = x + y * pix->CW;
	  if (x && y && x < pix->CW - 1 && y < pix->CH)
	    {
	      calculate_box(box, pos, pix);
	      savpix[pos].argb[RED_CMP] = box->red;
	      savpix[pos].argb[BLUE_CMP] = box->blue;
	      savpix[pos].argb[GREEN_CMP] = box->green;
	    }
	  else
	    savpix[pos].full = pixels[pos];
	}
    }
}

int			box_filtering(t_bunny_pixelarray **pix,
				      const int effect)
{
  t_boxe		box;
  t_bunny_pixelarray	*save;

  if (!(save = bunny_new_pixelarray((*pix)->CW,
				    (*pix)->CH)))
    return (1);
  init_box(box.box, (*pix)->CW);
  init_kernel_functab(&box);
  box.init_kernel[effect](box.kernel);
  box.div = ((box.div = box_divisor(box.kernel)) != 0) ? box.div : 1.0;
  apply_box_filter(*pix, save, &box);
  bunny_delete_clipable(&(*pix)->clipable);
  *pix = save;
  return (0);
}
