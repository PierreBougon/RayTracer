/*
** move_eye.c for move in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 17 18:34:07 2016 bougon_p
** Last update Sun Apr 17 18:54:09 2016 bougon_p
*/

#include "raytracer.h"

void				move_eye(t_data *data)
{
  const t_bunny_position	*mpos;

  mpos = bunny_get_mouse_position();
  if (!data->itfc.move.needmoving)
    {
      data->itfc.move.first_pos = *mpos;
      data->itfc.move.needmoving = true;
    }
  else
    {
      data->itfc.move.second_pos = *mpos;
      data->rt.eye.pos.x +=
	(data->itfc.move.second_pos.x - data->itfc.move.first_pos.x) * 10;
      data->rt.eye.pos.y +=
	(data->itfc.move.second_pos.y - data->itfc.move.first_pos.y) * 10;
      data->itfc.move.needmoving = false;
    }
}
