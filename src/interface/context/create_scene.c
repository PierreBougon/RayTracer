/*
** create_scene.c for scene in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May  1 02:25:51 2016 bougon_p
** Last update Mon May  2 01:57:05 2016 bougon_p
*/

#include "raytracer.h"

int	create_scene(t_data *data)
{
  if (data->click_action)
    {
      if (data->rt.img != NULL)
	clear_list(data->rt.obj);
      if ((data->rt.img =
	   bunny_new_pixelarray(data->rt.width,
				data->rt.height)) == NULL)
	return (1);
      data->rt.eye.pos.x = 0.0;
      data->rt.eye.pos.y = 0.0;
      data->rt.eye.pos.z = 0.0;
      data->rt.eye.rot.x = 0;
      data->rt.eye.rot.y = 0;
      data->rt.eye.rot.z = 0;
      data->rt.opt.ambient = 10.0 / 100.0;
      data->rt.opt.aa = 1;
      data->rt.obj_hit = NULL;
      data->rt.obj = NULL;
      data->click_action = false;
      data->rt.pos = center_rt(&data->rt);
    }
  else
    data->click_action = false;
  return (0);
}
