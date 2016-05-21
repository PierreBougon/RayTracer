/*
** blit.c for blit in /home/bougon_p/rendu/gfx_raytracer2/extra_fct
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 20 16:14:28 2016 bougon_p
** Last update Sat May 21 14:02:37 2016 bougon_p
*/

#include "lapin.h"
#include "data.h"

unsigned int         get_color(t_bunny_pixelarray *pix, t_bunny_position pos)
{
  t_color	     *color;

  color = (t_color *)pix->pixels + pos.x +
    (pos.y * pix->clipable.clip_width);
  return (color->full);
}

void			fill_pxlarray(t_bunny_pixelarray *pxar,
				      unsigned int color)
{
  int                   i;
  int                   j;
  t_color               col;
  t_bunny_position      pxpos;

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

void			fill_pxlarray_alpha(t_data *data)
{
  t_cols		c;
  unsigned int		alpha;
  unsigned int		inv_alpha;
  t_bunny_position      pxpos;

  pxpos.y = -1;
  while (++pxpos.y < 480)
    {
      pxpos.x = -1;
      while (++pxpos.x < 800)
        {
	  c.col1.full = get_color(data->px1, pxpos);
	  c.col2.full = get_color(data->px2, pxpos);
	  alpha = c.col1.argb[3] + 1;
	  inv_alpha = 255 - c.col1.argb[3];
	  c.colres.argb[0] = (unsigned char)
	    ((alpha * c.col1.argb[0] + inv_alpha * c.col2.argb[0]) >> 8);
	  c.colres.argb[1] = (unsigned char)
	    ((alpha * c.col1.argb[1] + inv_alpha * c.col2.argb[1]) >> 8);
	  c.colres.argb[2] = (unsigned char)
	    ((alpha * c.col1.argb[2] + inv_alpha * c.col2.argb[2]) >> 8);
	  c.colres.argb[3] = 255;
          tekpixel(data->res, &pxpos, &c.colres);
        }
    }
}

t_bunny_response        mainloop(void *_data)
{
  t_data                        *data;

  data = _data;
  fill_pxlarray_alpha(data);
  bunny_blit(&data->win->buffer, &data->res->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

int	main()
{
  t_data	data;

  if ((data.win = bunny_start(800, 480, 0, "BLIT")) == NULL)
    return (1);
  if ((data.px2 =
       bunny_load_pixelarray("led_strips_abstract2.bmp")) == NULL)
    return (1);
  if ((data.px1 =
       bunny_load_pixelarray("des.png")) == NULL)
    return (1);
  if ((data.res =
       bunny_new_pixelarray(800, 480)) == NULL)
    return (1);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, 30, &data);
  bunny_delete_clipable(&data.px1->clipable);
  bunny_delete_clipable(&data.px2->clipable);
  bunny_delete_clipable(&data.res->clipable);
  bunny_stop(data.win);
  return (0);
}
