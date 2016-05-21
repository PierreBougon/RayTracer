/*
** check_key.c for check in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 18:19:19 2016 bougon_p
** Last update Mon May 16 18:59:04 2016 bougon_p
*/

#include "raytracer.h"

int	check_key(t_data *data, UNUSED t_bunny_event_state state,
		  t_bunny_keysym key)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      if (key == data->itfc.key.key_move[i])
	data->itfc.key.f_key_move[i](data);
      i++;
    }
  i = 0;
  while (i < 4)
    {
      if (key == data->itfc.key.key_rot[i])
	data->itfc.key.f_key_rot[i](data);
      i++;
    }
  return (0);
}
