/*
** save_ini_obj_scope_cylinder.c
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 18:18:12 2016 bougon_p
** Last update Mon May  2 17:40:20 2016 romain samuel
*/

#include "raytracer.h"

static	void	cylinder_pos(t_cylinder *cyl,
			     t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(cyl->pos.x);
  bunny_ini_set_field(ini, scope, "pos", 0, value);
  bunny_free(value);
  value = setnbr(cyl->pos.y);
  bunny_ini_set_field(ini, scope, "pos", 1, value);
  bunny_free(value);
  value = setnbr(cyl->pos.z);
  bunny_ini_set_field(ini, scope, "pos", 2, value);
  bunny_free(value);
}

static	void	cylinder_rot(t_cylinder *cyl,
			     t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(cyl->rot.x);
  bunny_ini_set_field(ini, scope, "rot", 0, value);
  bunny_free(value);
  value = setnbr(cyl->rot.y);
  bunny_ini_set_field(ini, scope, "rot", 1, value);
  bunny_free(value);
  value = setnbr(cyl->rot.z);
  bunny_ini_set_field(ini, scope, "rot", 2, value);
  bunny_free(value);
}

static	void	cylinder_coef(t_cylinder *cyl,
			      t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(cyl->ka * 100);
  bunny_ini_set_field(ini, scope, "ka", 0, value);
  bunny_free(value);
  value = setnbr(cyl->kd * 100);
  bunny_ini_set_field(ini, scope, "kd", 0, value);
  bunny_free(value);
  value = setnbr(cyl->ks * 100);
  bunny_ini_set_field(ini, scope, "ks", 0, value);
  bunny_free(value);
  value = setnbr(cyl->brightness * 100);
  bunny_ini_set_field(ini, scope, "brightness", 0, value);
  bunny_free(value);
  value = setnbr(cyl->reflection * 100);
  bunny_ini_set_field(ini, scope, "reflection", 0, value);
  bunny_free(value);
  value = setnbr(cyl->opacity);
  bunny_ini_set_field(ini, scope, "opacity", 0, value);
  bunny_free(value);
}

void		cylinder_obj(t_data *data, t_object *obj,
			     t_bunny_ini *ini, int i)
{
  char		*value;
  char		*scope;
  t_cylinder	*cyl;

  cyl = obj->datas;
  scope = data->itfc.save.obj_names[i];
  bunny_ini_set_field(ini, scope, "type", 0, "cylinder");
  cylinder_pos(cyl, ini, scope);
  cylinder_rot(cyl, ini, scope);
  bunny_ini_set_field(ini, scope, "real", 0, "1");
  value = setnbr(cyl->tex_type);
  bunny_ini_set_field(ini, scope, "tex_type", 0, value);
  bunny_free(value);
  value = setnbr(cyl->size);
  bunny_ini_set_field(ini, scope, "size", 0, value);
  bunny_free(value);
  value = setnbr(cyl->height);
  bunny_ini_set_field(ini, scope, "height", 0, value);
  bunny_free(value);
  cylinder_coef(cyl, ini, scope);
  value = put_base(cyl->color1.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color", 0, value);
  bunny_free(value);
}
