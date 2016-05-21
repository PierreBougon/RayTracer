/*
** basic_wallpaper.c for wp in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May  2 01:56:49 2016 bougon_p
** Last update Sat May 21 17:41:30 2016 bougon_p
*/

#include "raytracer.h"

static	int	add_baswp_obj(t_data *data)
{
  data->rt.opt.skybox = 1;
  if (!(data->rt.opt.skybox_right = bunny_load_pixelarray
	("assets/img/DarkStormyRight2048.png")) ||
      !(data->rt.opt.skybox_left = bunny_load_pixelarray
	("assets/img/DarkStormyLeft2048.png")) ||
      !(data->rt.opt.skybox_up = bunny_load_pixelarray
	("assets/img/DarkStormyUp2048.png")) ||
      !(data->rt.opt.skybox_down = bunny_load_pixelarray
	("assets/img/DarkStormyDown2048.png")) ||
      !(data->rt.opt.skybox_forward = bunny_load_pixelarray
	("assets/img/DarkStormyFront2048.png")) ||
      !(data->rt.opt.skybox_backward = bunny_load_pixelarray
	("assets/img/DarkStormyBack2048.png")))
    return (my_puterr("Could not create wallpaper"), 1);
  return (0);
}

static	int	set_names(t_data *data)
{
  if (!(data->rt.opt.skybox_right_tex_name = my_strdup
      	("assets/img/DarkStormyRight2048.png")) ||
      !(data->rt.opt.skybox_left_tex_name = my_strdup
      	("assets/img/DarkStormyLeft2048.png")) ||
      !(data->rt.opt.skybox_up_tex_name = my_strdup
      	("assets/img/DarkStormyUp2048.png")) ||
      !(data->rt.opt.skybox_down_tex_name = my_strdup
      	("assets/img/DarkStormyDown2048.png")) ||
      !(data->rt.opt.skybox_front_tex_name = my_strdup
      	("assets/img/DarkStormyFront2048.png")) ||
      !(data->rt.opt.skybox_back_tex_name = my_strdup
      	("assets/img/DarkStormyBack2048.png")))
    return (my_puterr("Could not perform bunny malloc"), 1);
  return (0);
}

int	basic_wallpaper(t_data *data)
{
  if (data->rt.img != NULL
      && data->click_action)
    {
      if (add_baswp_obj(data) == 1
	  || set_names(data) == 1)
	return (1);
      data->click_action = false;
    }
  else
    data->click_action = false;
  return (0);
}
