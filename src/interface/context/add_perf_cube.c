/*
** add_perf_cube.c for perf cube in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 24 18:11:17 2016 bougon_p
** Last update Sun May 22 18:11:02 2016 benjamin duhieu
*/

#include "raytracer.h"

int	add_perf_cube(UNUSED t_data *data)
{
  if (data->rt.img != NULL
      && data->click_action
      && data->itfc.mpos->x > data->rt.pos.x
      && data->itfc.mpos->x < data->rt.pos.x +
      data->rt.img->clipable.clip_width
      && data->itfc.mpos->y > data->rt.pos.y
      && data->itfc.mpos->y < data->rt.pos.y +
      data->rt.img->clipable.clip_height)
    data->click_action = false;
  else
    data->click_action = false;
  return (0);
}
