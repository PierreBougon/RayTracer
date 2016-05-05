/*
** basic_wallpaper.c for wp in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May  2 01:56:49 2016 bougon_p
** Last update Thu May  5 21:09:09 2016 romain samuel
*/

#include "raytracer.h"

static	void	pos_baswp(t_plan *pla)
{
  pla->pos.x = 0;
  pla->pos.y = 0;
  pla->pos.z = 500000;
  pla->rot.x = 0;
  pla->rot.y = 0;
  pla->rot.z = 0;
}

static	int	add_baswp_obj(t_data *data)
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
  pos_baswp(pla);
  pla->tex_type = 1;
  pla->width = 5000;
  pla->height = 5000;
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

int	basic_wallpaper(t_data *data)
{
  if (data->rt.img != NULL
      && data->click_action)
    {
      if (add_baswp_obj(data) == 1)
	return (1);
      data->click_action = false;
    }
  else
    data->click_action = false;
  return (0);
}
