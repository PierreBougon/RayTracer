/*
** add_sphere.c for sphere in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Apr 24 17:59:29 2016 bougon_p
** Last update Sun May  1 19:21:22 2016 bougon_p
*/

#include "raytracer.h"

static	void	pos_sphere(t_data *data, t_sphere *sph)
{
  t_acc		vec;

  vec.x = 0;
  vec.y = 0;
  vec.z = 8000;
  sph->pos.x = data->rt.eye.pos.x;
  sph->pos.y = data->rt.eye.pos.y;
  sph->pos.z = data->rt.eye.pos.z;
  translation_obj(&vec, &data->rt.eye.rot, &sph->pos);
  sph->rot.x = 0;
  sph->rot.y = 0;
  sph->rot.z = 0;
}

static	int	add_sphere_obj(t_data *data)
{
  t_object	*new;
  t_sphere	*sph;

  if ((sph = malloc(sizeof(t_sphere))) == NULL)
    return (1);
  if (data->rt.obj != NULL)
    new = add_obj_elem_ret(data->rt.obj);
  else
    {
      data->rt.obj = create_obj_list();
      new = data->rt.obj;
    }
  pos_sphere(data, sph);
  sph->tex_type = 1;
  sph->size = 1000;
  sph->ka = 1.0;
  sph->kd = 1.0;
  sph->ks = 1.0;
  sph->brightness = 0.0;
  sph->reflection = 0.0;
  sph->opacity = 1.0;
  sph->color.full = OBJ_COLOR;
  new->datas = sph;
  new->type = SPHERE;
  return (0);
}

int	add_sphere(t_data *data)
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
      if (add_sphere_obj(data) == 1)
	return (1);
    }
  else
    data->click_action = false;
  return (0);
}
