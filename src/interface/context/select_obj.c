/*
** select_obj.c for select in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 20 16:32:36 2016 bougon_p
** Last update Sun May 22 14:04:42 2016 bougon_p
*/

#include "raytracer.h"

int	select_obj(t_data *data)
{
  if (check_workspace(data->itfc.mpos, &data->rt)
      && data->click_action)
    {
      data->itfc.obj_selected =
      	get_obj(&data->rt,
      		data->itfc.mpos->x - data->rt.pos.x,
		data->itfc.mpos->y - data->rt.pos.y);
    }
  data->click_action = false;
  return (0);
}
