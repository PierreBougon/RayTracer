/*
** basic_plane.c for  in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May  2 01:52:59 2016 bougon_p
** Last update Sat May 21 14:23:22 2016 bougon_p
*/

#include "raytracer.h"

static	void	pos_basplane(t_plan *pla)
{
  pla->pos.x = 0;
  pla->pos.y = -20000;
  pla->pos.z = 30000;
  pla->rot.x = 90;
  pla->rot.y = 0;
  pla->rot.z = 0;
  pla->tex_type = 1;
  pla->width = 500000;
  pla->height = 500000;
  pla->ka = 1.0;
  pla->kd = 1.0;
  pla->ks = 1.0;
}

static	int	add_basplane_obj(t_data *data)
{
  t_object	*new;
  t_plan	*pla;

  if ((pla = bunny_malloc(sizeof(t_plan))) == NULL)
    return (1);
  if (data->rt.obj != NULL)
    new = add_obj_elem_ret(data->rt.obj);
  else
    {
      data->rt.obj = create_obj_list();
      new = data->rt.obj;
    }
  pos_basplane(pla);
  pla->refraction = 1.0;
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

int	basic_plane(t_data *data)
{
  if (data->rt.img != NULL
      && data->click_action)
    {
      if (add_basplane_obj(data) == 1)
	return (1);
      data->click_action = false;
    }
  else
    data->click_action = false;
  return (0);
}
