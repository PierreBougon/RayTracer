/*
** save_ini_obj_scope_light.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 18:35:33 2016 bougon_p
** Last update Sun May 22 18:13:42 2016 benjamin duhieu
*/

#include "raytracer.h"

void		light_obj(t_data *data, t_object *obj,
			  t_bunny_ini *ini, int i)
{
  char		*value;
  char		*scope;
  t_light	*light;

  light = obj->datas;
  scope = data->itfc.save.obj_names[i];
  bunny_ini_set_field(ini, scope, "type", 0, "light");
  value = setnbr(light->pos.x);
  bunny_ini_set_field(ini, scope, "pos", 0, value);
  bunny_free(value);
  value = setnbr(light->pos.y);
  bunny_ini_set_field(ini, scope, "pos", 1, value);
  bunny_free(value);
  value = setnbr(light->pos.z);
  bunny_ini_set_field(ini, scope, "pos", 2, value);
  bunny_free(value);
  value = setnbr(light->intensity * 100);
  bunny_ini_set_field(ini, scope, "intensity", 0, value);
  bunny_free(value);
  value = put_base(light->color.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color", 0, value);
  bunny_free(value);
}
