/*
** load_light.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 17:15:43 2016 romain samuel
** Last update Thu Apr 28 18:50:53 2016 romain samuel
*/

#include "raytracer.h"

int		load_light_datas(t_light *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing light x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing light y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing light z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "intensity", 0)) == NULL)
    return (my_puterr("load_datas: missing light intensity"));
  s->intensity = (double)my_getnbr((char *)field) / 100.0;
  if ((field = bunny_ini_get_field(ini, scope, "color", 0)) == NULL)
    return (my_puterr("load_datas: missing light color"));
  s->color.full = my_getcolor((char *)field, "0123456789ABCDEF");
  return (0);
}

int		load_light(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_light	*s;

  if ((s = malloc(sizeof(t_light))) == NULL)
    return (-1);
  if (rt->obj == NULL)
    {
      if ((rt->obj = create_obj_list()) == NULL)
	return (-1);
    }
  else
    {
      if (add_obj_elem(rt->obj) == -1)
	return (-1);
    }
  it = rt->obj;
  while (it->next != NULL)
    it = it->next;
  it->type = 5;
  if (load_light_datas(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  return (0);
}
