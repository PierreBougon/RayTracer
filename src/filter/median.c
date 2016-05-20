/*
** median.c in RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 20:59:39 2016 marc brout
** Last update Wed May 18 21:01:48 2016 marc brout
*/

#include "glass.h"

int			median_filter(t_bunny_pixelarray **pix)
{
  t_bunny_pixelarray	*save;

  if (!(save = bunny_new_pixelarray((*pix)->clipable.clip_width,
				    (*pix)->clipable.clip_height)))
    return (1);
  apply_median(*pix, save, (*pix)->clipable.clip_width,
	       (*pix)->clipable.clip_height);
  bunny_delete_clipable(&(*pix)->clipable);
  *pix = save;
  return (0);
}

int			glass(t_bunny_pixelarray **pix)
{
  t_bunny_pixelarray	*save;

  if (!(save = bunny_new_pixelarray((*pix)->clipable.clip_width,
				    (*pix)->clipable.clip_height)))
    return (1);
  apply_shatter(*pix, save, (*pix)->clipable.clip_width,
		(*pix)->clipable.clip_height);
  bunny_delete_clipable(&(*pix)->clipable);
  *pix = save;
  if (median_filter(pix) || median_filter(pix) || median_filter(pix))
    return (1);
  return (0);
}
