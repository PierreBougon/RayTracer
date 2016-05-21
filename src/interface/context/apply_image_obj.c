/*
** apply_image_obj.c for texture in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat May 21 03:56:00 2016 bougon_p
** Last update Sat May 21 06:33:57 2016 bougon_p
*/

#include "raytracer.h"

int		apply_sphere(t_data *data)
{
  t_sphere	*sph;

  sph = data->itfc.obj_selected->datas;
  if (!sph->texture && ((sph->texture =
			 bunny_load_pixelarray
			 ("assets/img/stone3.jpg")) == NULL))
    return (my_puterr("load_datas: invalid sphere texture"), 1);
  sph->tex_type = IMAGE;
  data->itfc.past.rad_state = IMG;
  return (0);
}

int		apply_cone(UNUSED t_data *data)
{
  return (0);
}

int		apply_cylinder(t_data *data)
{
  t_cylinder	*cyl;

  cyl = data->itfc.obj_selected->datas;
  if (!cyl->texture1 && ((cyl->texture1 =
			  bunny_load_pixelarray
			  ("assets/img/stone3.jpg")) == NULL))
    return (my_puterr("load_datas: invalid cylinder texture"), 1);
  if (!cyl->texture2 && ((cyl->texture2 =
			  bunny_load_pixelarray
			  ("assets/img/stone3.jpg")) == NULL))
    return (my_puterr("load_datas: invalid cylinder texture"), 1);
  cyl->tex_type = IMAGE;
  data->itfc.past.rad_state = IMG;
  return (0);
}

int		apply_plan(t_data *data)
{
  t_plan	*pla;

  pla = data->itfc.obj_selected->datas;
  if (!pla->texture && ((pla->texture =
			 bunny_load_pixelarray
			  ("assets/img/stone3.jpg")) == NULL))
    return (my_puterr("load_datas: invalid plane texture"), 1);
  pla->tex_type = IMAGE;
  data->itfc.past.rad_state = IMG;
  return (0);
}
