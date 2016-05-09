/*
** set_size.c for size in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May  5 16:58:56 2016 bougon_p
** Last update Sun May  8 00:21:29 2016 bougon_p
*/

#include "raytracer.h"

int	set_full_size(t_data *data)
{
  if (data->rt.img != NULL)
    bunny_delete_clipable(&data->rt.img->clipable);
  else
    return (0);
  data->rt.width = FULL_WIDTH;
  data->rt.height = FULL_HEIGHT;
  if ((data->rt.img = bunny_new_pixelarray
       (data->rt.width, data->rt.height)) == NULL)
    return (1);
  data->rt.pos = center_rt(&data->rt);
  live_display(&data->rt);
  if (data->rt.img != NULL)
    bunny_blit(&data->win->buffer,
	       &data->rt.img->clipable, &data->rt.pos);
  return (0);
}

int	set_high_size(t_data *data)
{
  if (data->rt.img != NULL)
    bunny_delete_clipable(&data->rt.img->clipable);
  else
    return (0);
  data->rt.width = HIGH_WIDTH;
  data->rt.height = HIGH_HEIGHT;
  if ((data->rt.img = bunny_new_pixelarray
       (data->rt.width, data->rt.height)) == NULL)
    return (1);
  data->rt.pos = center_rt(&data->rt);
  live_display(&data->rt);
  if (data->rt.img != NULL)
    bunny_blit(&data->win->buffer,
	       &data->rt.img->clipable, &data->rt.pos);
  return (0);
}

int	set_hd_size(t_data *data)
{
  if (data->rt.img != NULL)
    bunny_delete_clipable(&data->rt.img->clipable);
  else
    return (0);
  data->rt.width = HD_WIDTH;
  data->rt.height = HD_HEIGHT;
  if ((data->rt.img = bunny_new_pixelarray
       (data->rt.width, data->rt.height)) == NULL)
    return (1);
  data->rt.pos = center_rt(&data->rt);
  live_display(&data->rt);
  if (data->rt.img != NULL)
    bunny_blit(&data->win->buffer,
	       &data->rt.img->clipable, &data->rt.pos);
  return (0);
}

int	set_xga_size(t_data *data)
{
  if (data->rt.img != NULL)
    bunny_delete_clipable(&data->rt.img->clipable);
  else
    return (0);
  data->rt.width = XGA_WIDTH;
  data->rt.height = XGA_HEIGHT;
  if ((data->rt.img = bunny_new_pixelarray
       (data->rt.width, data->rt.height)) == NULL)
    return (1);
  data->rt.pos = center_rt(&data->rt);
  live_display(&data->rt);
  if (data->rt.img != NULL)
    bunny_blit(&data->win->buffer,
	       &data->rt.img->clipable, &data->rt.pos);
  return (0);
}

int	set_vga_size(t_data *data)
{
  if (data->rt.img != NULL)
    bunny_delete_clipable(&data->rt.img->clipable);
  else
    return (0);
  data->rt.width = VGA_WIDTH;
  data->rt.height = VGA_HEIGHT;
  if ((data->rt.img = bunny_new_pixelarray
       (data->rt.width, data->rt.height)) == NULL)
    return (1);
  data->rt.pos = center_rt(&data->rt);
  live_display(&data->rt);
  if (data->rt.img != NULL)
    bunny_blit(&data->win->buffer,
	       &data->rt.img->clipable, &data->rt.pos);
  return (0);
}
