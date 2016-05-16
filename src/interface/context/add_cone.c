/*
** add_cone.c for cone in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 24 18:03:39 2016 bougon_p
** Last update Thu May  5 21:07:55 2016 romain samuel
*/

#include "raytracer.h"

static	void	pos_cone(t_data *data, t_cone *con)
{
  t_acc		vec;

  vec.x = 0;
  vec.y = 0;
  vec.z = 10000;
  con->pos.x = data->rt.eye.pos.x;
  con->pos.y = data->rt.eye.pos.y;
  con->pos.z = data->rt.eye.pos.z;
  translation_obj(&data->rt.rotation,
		  &vec, &data->rt.eye.rot, &con->pos);
  con->rot.x = 90;
  con->rot.y = 0;
  con->rot.z = 0;
}

static	int	add_cone_obj(t_data *data)
{
  t_object	*new;
  t_cone	*con;

  if ((con = bunny_malloc(sizeof(t_cone))) == NULL)
    return (1);
  if (data->rt.obj != NULL)
    new = add_obj_elem_ret(data->rt.obj);
  else
    {
      data->rt.obj = create_obj_list();
      new = data->rt.obj;
    }
  pos_cone(data, con);
  con->tex_type = 1;
  con->angle = 80;
  con->height = 5000;
  con->ka = 1.0;
  con->kd = 1.0;
  con->ks = 1.0;
  con->brightness = 0.0;
  con->reflection = 0.0;
  con->opacity = 1.0;
  con->color1.full = OBJ_COLOR;
  new->datas = con;
  new->type = CONE;
  return (0);
}

int	add_cone(UNUSED t_data *data)
{
  if (data->rt.img != NULL
      && data->click_action
      && data->itfc.mpos->x > data->rt.pos.x
      && data->itfc.mpos->x < data->rt.pos.x +
      data->rt.img->clipable.clip_width
      && data->itfc.mpos->y > data->rt.pos.y
      && data->itfc.mpos->y < data->rt.pos.y +
      data->rt.img->clipable.clip_height)
    {
      data->click_action = false;
      if (add_cone_obj(data) == 1)
	return (1);
    }
  else
    data->click_action = false;
  return (0);
}
