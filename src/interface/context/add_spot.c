/*
** add_spot.c for add in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 17 14:53:45 2016 bougon_p
** Last update Wed May 18 15:24:38 2016 bougon_p
*/

#include "raytracer.h"

static t_light	*fill_light(t_data *data, t_light *light)
{
  t_acc		vec;

  light->color.full = WHITE;
  light->intensity = 0.50;
  vec.x = 0;
  vec.y = 0;
  vec.z = 1000;
  light->pos.x = data->rt.eye.pos.x;
  light->pos.y = data->rt.eye.pos.y;
  light->pos.z = data->rt.eye.pos.z;
  translation_obj(&data->rt.rotation, &vec, &data->rt.eye.rot,
		  &light->pos);
  return (light);
}

int	add_spot(t_data *data)
{
  t_object	*obj;
  t_object	*new;
  t_light	*light;

  if (data->click_action)
    {
      obj = data->rt.obj;
      if (!(light = malloc(sizeof(t_light))))
	return (1);
      if (!data->rt.obj)
	new = add_obj_elem_ret(data->rt.obj);
      else
	{
	  data->rt.obj = create_obj_list();
	  new = data->rt.obj;
	}
      new->next = obj;
      new->type = LIGHT;
      new->real = 1;
      new->datas = fill_light(data, light);
      data->itfc.light_selected = new;
    }
  data->click_action = false;
  return (0);
}
