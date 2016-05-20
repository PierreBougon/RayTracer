/*
** filter.c for rt2 in ~RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri May 20 12:58:40 2016 marc brout
** Last update Fri May 20 22:07:23 2016 marc brout
*/

#include "raytracer.h"
#include "box_filtering.h"
#include "glass.h"
#include "oil_effect.h"
#include "sobel.h"

static void		copy_pixelarray(t_bunny_pixelarray *_pix,
					t_bunny_pixelarray *_save,
					const int width,
					const int height)
{
  unsigned int		*pix;
  unsigned int		*save;
  int			i;
  int			total;

  i = 0;
  pix = _pix->pixels;
  save = _save->pixels;
  total = width * height;
  while (i < total - 1)
    {
      save[i] = pix[i];
      ++i;
    }
}

static t_bunny_pixelarray	*save_pixelarray(t_bunny_pixelarray *pix)
{
  t_bunny_pixelarray		*save;

  if (!(save = bunny_new_pixelarray(pix->clipable.clip_width,
				    pix->clipable.clip_height)))
    return (NULL);
  copy_pixelarray(pix, save, pix->clipable.clip_width,
		  pix->clipable.clip_height);
  return (save);
}

static void		restore_pixelarray(t_bunny_pixelarray **pix,
					   t_bunny_pixelarray *save)
{
  bunny_delete_clipable(&(*pix)->clipable);
  *pix = save;
}

static void		init_filter_tab(t_data *data)
{
  data->rt.ftabs.filter_effect[RAISED_F] = &box_filtering;
  data->rt.ftabs.filter_effect[SMOOTH_F] = &box_filtering;
  data->rt.ftabs.filter_effect[SHARPEN_F] = &box_filtering;
  data->rt.ftabs.filter_effect[BLUR_F] = &box_filtering;
  data->rt.ftabs.filter_effect[EDGE_F] = &box_filtering;
  data->rt.ftabs.filter_effect[BORDERLAND_F] = &borderland;
  data->rt.ftabs.filter_effect[OIL_F] = &oil;
  data->rt.ftabs.filter_effect[GLASS_F] = &glass;
  data->rt.ftabs.filter_effect[MEDIAN_F] = &median_filter;
}

int			keys_filter(t_bunny_keysym keysym,
				    void *_data)
{
  static int		save = 0;
  t_data		*data;

  data = _data;
  init_filter_tab(data);
  if (keysym >= BKS_0 && keysym <= BKS_9)
    {
      if (!save)
	{
	  if (!(data->rt.save = save_pixelarray(data->rt.img)))
	    return (1);
	  save = 1;
	}
      if (keysym < BKS_9)
	{
	  if (data->rt.ftabs.filter_effect[(int)keysym - BKS_0]
	      (&data->rt.img, (int)(keysym) + 1 - BKS_0))
	    return (1);
	}
    }
  else if (save && keysym == BKS_N)
    {
      restore_pixelarray(&data->rt.img, data->rt.save);
      save = 0;
    }
  return (0);
}
