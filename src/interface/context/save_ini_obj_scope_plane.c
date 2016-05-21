/*
** save_ini_obj_scope_plane.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 18:18:29 2016 bougon_p
** Last update Sat May 21 17:36:07 2016 bougon_p
*/

#include "raytracer.h"

static	void	plane_pos(t_plan *pla,
			   t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(pla->pos.x);
  bunny_ini_set_field(ini, scope, "pos", 0, value);
  bunny_free(value);
  value = setnbr(pla->pos.y);
  bunny_ini_set_field(ini, scope, "pos", 1, value);
  bunny_free(value);
  value = setnbr(pla->pos.z);
  bunny_ini_set_field(ini, scope, "pos", 2, value);
  bunny_free(value);
}

static	void	plane_rot(t_plan *pla,
			   t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(pla->rot.x);
  bunny_ini_set_field(ini, scope, "rot", 0, value);
  bunny_free(value);
  value = setnbr(pla->rot.y);
  bunny_ini_set_field(ini, scope, "rot", 1, value);
  bunny_free(value);
  value = setnbr(pla->rot.z);
  bunny_ini_set_field(ini, scope, "rot", 2, value);
  bunny_free(value);
}

static	void	plane_coef(t_plan *pla,
			    t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(pla->ka * 100);
  bunny_ini_set_field(ini, scope, "ka", 0, value);
  bunny_free(value);
  value = setnbr(pla->kd * 100);
  bunny_ini_set_field(ini, scope, "kd", 0, value);
  bunny_free(value);
  value = setnbr(pla->ks * 100);
  bunny_ini_set_field(ini, scope, "ks", 0, value);
  bunny_free(value);
  value = setnbr(pla->brightness * 100);
  bunny_ini_set_field(ini, scope, "brightness", 0, value);
  bunny_free(value);
  value = setnbr(pla->reflection * 100);
  bunny_ini_set_field(ini, scope, "reflection", 0, value);
  bunny_free(value);
  value = setnbr(pla->opacity * 100);
  bunny_ini_set_field(ini, scope, "opacity", 0, value);
  bunny_free(value);
}

static	void	set_values(t_plan *pla,
			   t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(pla->height * 2);
  bunny_ini_set_field(ini, scope, "height", 0, value);
  bunny_free(value);
  value = setnbr(pla->width * 2);
  bunny_ini_set_field(ini, scope, "width", 0, value);
  bunny_free(value);
  plane_coef(pla, ini, scope);
  value = put_base(pla->color1.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color1", 0, value);
  bunny_free(value);
  value = put_base(pla->color2.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color2", 0, value);
  bunny_free(value);
  value = setnbr(pla->refraction);
  bunny_ini_set_field(ini, scope, "refraction", 0, value);
  bunny_free(value);
  bunny_ini_set_field(ini, scope, "case_size", 0, "2000");
}

void		plane_obj(t_data *data, t_object *obj,
			  t_bunny_ini *ini, int i)
{
  char		*value;
  char		*scope;
  t_plan	*pla;

  pla = obj->datas;
  scope = data->itfc.save.obj_names[i];
  bunny_ini_set_field(ini, scope, "type", 0, "plan");
  plane_pos(pla, ini, scope);
  plane_rot(pla, ini, scope);
  value = setnbr(pla->tex_type);
  bunny_ini_set_field(ini, scope, "tex_type", 0, value);
  bunny_free(value);
  set_values(pla, ini, scope);
  if (pla->tex_name)
    bunny_ini_set_field(ini, scope, "texture", 0, pla->tex_name);
}
