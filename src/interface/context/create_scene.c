/*
** create_scene.c for scene in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May  1 02:25:51 2016 bougon_p
** Last update Sun May 22 16:14:34 2016 bougon_p
*/

#include "raytracer.h"

static void	set_value(t_data *data)
{
  data->rt.eye.pos.x = 0.0;
  data->rt.eye.pos.y = 0.0;
  data->rt.eye.pos.z = 0.0;
  data->rt.eye.rot.x = 0;
  data->rt.eye.rot.y = 0;
  data->rt.eye.rot.z = 0;
  data->rt.opt.ambient = 10.0 / 100.0;
  data->rt.opt.ambient_refraction = 1.0;
  data->rt.opt.aa = 1;
}

int	create_scene(t_data *data)
{
  if (data->click_action)
    {
      if (data->rt.img != NULL)
	clear_full_list(data->rt.obj, &data->rt.ftabs);
      if ((data->rt.img =
	   bunny_new_pixelarray(data->rt.width,
				data->rt.height)) == NULL)
	return (1);
      set_value(data);
      data->rt.obj_hit = NULL;
      data->rt.obj = NULL;
      data->click_action = false;
      data->rt.pos = center_rt(&data->rt);
      data->rt.opt.skybox = 0;
      data->rt.opt.ss = 0;
      data->rt.opt.nb_rays_ss = 1;
      data->rt.opt.ray_ss = 0;
      live_display(&data->rt);
      bunny_blit(&data->win->buffer, &data->rt.img->clipable, &data->rt.pos);
    }
  else
    data->click_action = false;
  return (0);
}
