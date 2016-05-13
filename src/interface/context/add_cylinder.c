/*
** add_cylinder.c for cylinder in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 24 18:04:18 2016 bougon_p
** Last update Thu May  5 21:08:09 2016 romain samuel
*/

#include "raytracer.h"

static	void	pos_cylinder(t_data *data, t_cylinder *cyl)
{
  t_acc		vec;

  vec.x = 0;
  vec.y = 0;
  vec.z = 15000;
  cyl->pos.x = data->rt.eye.pos.x;
  cyl->pos.y = data->rt.eye.pos.y;
  cyl->pos.z = data->rt.eye.pos.z;
  translation_obj(&data->rt.rotation,
		  &vec, &data->rt.eye.rot, &cyl->pos);
  cyl->rot.x = 90;
  cyl->rot.y = 0;
  cyl->rot.z = 0;
}

static	int	add_cylinder_obj(t_data *data)
{
  t_object	*new;
  t_cylinder	*cyl;

  if ((cyl = bunny_malloc(sizeof(t_cylinder))) == NULL)
    return (1);
  if (data->rt.obj != NULL)
    new = add_obj_elem_ret(data->rt.obj);
  else
    {
      data->rt.obj = create_obj_list();
      new = data->rt.obj;
    }
  pos_cylinder(data, cyl);
  cyl->tex_type = 1;
  cyl->size = 2000;
  cyl->height = 5000;
  cyl->ka = 1.0;
  cyl->kd = 1.0;
  cyl->ks = 1.0;
  cyl->brightness = 0.0;
  cyl->reflection = 0.0;
  cyl->opacity = 1.0;
  cyl->color1.full = OBJ_COLOR;
  new->datas = cyl;
  new->type = CYLINDER;
  return (0);
}

int	add_cylinder(UNUSED t_data *data)
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
      if (add_cylinder_obj(data) == 1)
	return (1);
    }
  else
    data->click_action = false;
  return (0);
}
