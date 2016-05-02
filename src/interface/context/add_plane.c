/*
** add_plan.c for plan in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 24 18:02:53 2016 bougon_p
** Last update Mon May  2 17:08:59 2016 marc brout
*/

#include "raytracer.h"

static	void	pos_plane(t_data *data, t_plan *pla)
{
  t_acc		vec;

  vec.x = 0;
  vec.y = 0;
  vec.z = 30000;
  pla->pos.x = data->rt.eye.pos.x;
  pla->pos.y = data->rt.eye.pos.y;
  pla->pos.z = data->rt.eye.pos.z;
  translation_obj(&data->rt.rotation,
		  &vec, &data->rt.eye.rot, &pla->pos);
  pla->rot.x = 0;
  pla->rot.y = 0;
  pla->rot.z = 0;
}

static	int	add_plane_obj(t_data *data)
{
  t_object	*new;
  t_plan	*pla;

  if ((pla = malloc(sizeof(t_plan))) == NULL)
    return (1);
  if (data->rt.obj != NULL)
    new = add_obj_elem_ret(data->rt.obj);
  else
    {
      data->rt.obj = create_obj_list();
      new = data->rt.obj;
    }
  pos_plane(data, pla);
  pla->tex_type = 1;
  pla->width = 500;
  pla->height = 500;
  pla->ka = 1.0;
  pla->kd = 1.0;
  pla->ks = 1.0;
  pla->brightness = 0.0;
  pla->reflection = 0.0;
  pla->opacity = 1.0;
  pla->color1.full = WHITE;
  pla->color2.full = BLACK;
  pla->case_size = 2000;
  new->datas = pla;
  new->type = PLANE;
  return (0);
}

int	add_plane(UNUSED t_data *data)
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
      if (add_plane_obj(data) == 1)
	return (1);
    }
  else
    data->click_action = false;
  return (0);
}
