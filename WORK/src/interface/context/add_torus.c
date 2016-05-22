/*
** add_torus.c for torus in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 24 18:08:34 2016 bougon_p
** Last update Wed Apr 27 20:27:44 2016 bougon_p
*/

#include "raytracer.h"

int	add_torus(UNUSED t_data *data)
{
  if (data->rt.img != NULL
      && data->click_action
      && data->itfc.mpos->x > data->rt.pos.x
      && data->itfc.mpos->x < data->rt.pos.x +
      data->rt.img->clipable.clip_width
      && data->itfc.mpos->y > data->rt.pos.y
      && data->itfc.mpos->y < data->rt.pos.y +
      data->rt.img->clipable.clip_height)
    {
      data->click_action = false;
      printf("ADD TORUS\n");
    }
  else
    data->click_action = false;
  return (0);
}
