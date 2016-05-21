/*
** aplly_texture.c for apply_tec in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat May 21 02:49:03 2016 bougon_p
** Last update Sat May 21 06:32:01 2016 bougon_p
*/

#include "raytracer.h"

int		apply_flat_texture(t_data *data)
{
  t_sphere	*sph;
  t_cone	*con;
  t_cylinder	*cyl;
  t_plan	*pla;

  if (data->itfc.obj_selected->type == CONE)
    {
      con = data->itfc.obj_selected->datas;
      con->tex_type = FULL;
      data->itfc.past.rad_state = FLAT;
    }
  else if (data->itfc.obj_selected->type == SPHERE)
    {
      sph = data->itfc.obj_selected->datas;
      sph->tex_type = FULL;
      data->itfc.past.rad_state = FLAT;
    }
  else if (data->itfc.obj_selected->type == CYLINDER)
    {
      cyl = data->itfc.obj_selected->datas;
      cyl->tex_type = FULL;
      data->itfc.past.rad_state = FLAT;
    }
  else if (data->itfc.obj_selected->type == PLANE)
    {
      pla = data->itfc.obj_selected->datas;
      pla->tex_type = FULL;
      data->itfc.past.rad_state = FLAT;
    }
  return (0);
}

int	apply_perlin_texture(t_data *data)
{
  t_sphere	*sph;
  t_cone	*con;
  t_cylinder	*cyl;
  t_plan	*pla;

  if (data->itfc.obj_selected->type == CONE)
    {
      con = data->itfc.obj_selected->datas;
      con->tex_type = PERLIN_NOISE;
      data->itfc.past.rad_state = PERLIN;
    }
  else if (data->itfc.obj_selected->type == SPHERE)
    {
      sph = data->itfc.obj_selected->datas;
      sph->tex_type = PERLIN_NOISE;
      data->itfc.past.rad_state = PERLIN;
    }
  else if (data->itfc.obj_selected->type == CYLINDER)
    {
      cyl = data->itfc.obj_selected->datas;
      cyl->tex_type = PERLIN_NOISE;
      data->itfc.past.rad_state = PERLIN;
    }
  else if (data->itfc.obj_selected->type == PLANE)
    {
      pla = data->itfc.obj_selected->datas;
      pla->tex_type = PERLIN_NOISE;
      data->itfc.past.rad_state = PERLIN;
    }
  return (0);
}

int	apply_image_texture(t_data *data)
{
  if (data->itfc.fct_apply_image
      [data->itfc.obj_selected->type - 1](data) == 1)
    return (1);
  return (0);
}
