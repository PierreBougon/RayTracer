/*
** save_ini_obj_scope_cone.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 18:17:52 2016 bougon_p
** Last update Sat May 21 17:53:00 2016 bougon_p
*/

#include "raytracer.h"

static	void	cone_pos(t_cone *con,
			 t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(con->pos.x);
  bunny_ini_set_field(ini, scope, "pos", 0, value);
  bunny_free(value);
  value = setnbr(con->pos.y);
  bunny_ini_set_field(ini, scope, "pos", 1, value);
  bunny_free(value);
  value = setnbr(con->pos.z);
  bunny_ini_set_field(ini, scope, "pos", 2, value);
  bunny_free(value);
}

static	void	cone_rot(t_cone *con,
			 t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(con->rot.x);
  bunny_ini_set_field(ini, scope, "rot", 0, value);
  bunny_free(value);
  value = setnbr(con->rot.y);
  bunny_ini_set_field(ini, scope, "rot", 1, value);
  bunny_free(value);
  value = setnbr(con->rot.z);
  bunny_ini_set_field(ini, scope, "rot", 2, value);
  bunny_free(value);
}

static	void	cone_coef(t_cone *con,
			  t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(con->ka * 100);
  bunny_ini_set_field(ini, scope, "ka", 0, value);
  bunny_free(value);
  value = setnbr(con->kd * 100);
  bunny_ini_set_field(ini, scope, "kd", 0, value);
  bunny_free(value);
  value = setnbr(con->ks * 100);
  bunny_ini_set_field(ini, scope, "ks", 0, value);
  bunny_free(value);
  value = setnbr(con->brightness * 100);
  bunny_ini_set_field(ini, scope, "brightness", 0, value);
  bunny_free(value);
  value = setnbr(con->reflection * 100);
  bunny_ini_set_field(ini, scope, "reflection", 0, value);
  bunny_free(value);
  value = setnbr(con->opacity);
  bunny_ini_set_field(ini, scope, "opacity", 0, value);
  bunny_free(value);
}

static	void	set_values(t_cone *con,
			   char *scope, t_bunny_ini *ini)
{
  char		*value;

  value = setnbr(90 - con->angle);
  bunny_ini_set_field(ini, scope, "angle", 0, value);
  bunny_free(value);
  value = setnbr(con->height);
  bunny_ini_set_field(ini, scope, "height", 0, value);
  bunny_free(value);
  value = setnbr(con->refraction);
  bunny_ini_set_field(ini, scope, "refraction", 0, value);
  bunny_free(value);
  cone_coef(con, ini, scope);
  value = put_base(con->color1.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color1", 0, value);
  bunny_free(value);
  value = put_base(con->color2.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color2", 0, value);
  bunny_free(value);
}

void		cone_obj(t_data *data, t_object *obj,
			 t_bunny_ini *ini, int i)
{
  char		*value;
  char		*scope;
  t_cone	*con;

  con = obj->datas;
  scope = data->itfc.save.obj_names[i];
  bunny_ini_set_field(ini, scope, "type", 0, "cone");
  cone_pos(con, ini, scope);
  cone_rot(con, ini, scope);
  bunny_ini_set_field(ini, scope, "real", 0, "1");
  value = setnbr(con->tex_type);
  bunny_ini_set_field(ini, scope, "tex_type", 0, value);
  bunny_free(value);
  set_values(con, scope, ini);
  if (con->tex1_name)
    bunny_ini_set_field(ini, scope, "texture1", 0, con->tex1_name);
  if (con->tex2_name)
    bunny_ini_set_field(ini, scope, "texture2", 0, con->tex2_name);
}
