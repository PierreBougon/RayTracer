/*
** save_ini_obj_scope.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 17:08:46 2016 bougon_p
** Last update Fri Apr 29 22:46:42 2016 bougon_p
*/

#include "raytracer.h"

static	void	sphere_pos(t_sphere *sph,
			   t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(sph->pos.x);
  bunny_ini_set_field(ini, scope, "pos", 0, value);
  bunny_free(value);
  value = setnbr(sph->pos.y);
  bunny_ini_set_field(ini, scope, "pos", 1, value);
  bunny_free(value);
  value = setnbr(sph->pos.z);
  bunny_ini_set_field(ini, scope, "pos", 2, value);
  bunny_free(value);
}

static	void	sphere_rot(t_sphere *sph,
			   t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(sph->rot.x);
  bunny_ini_set_field(ini, scope, "rot", 0, value);
  bunny_free(value);
  value = setnbr(sph->rot.y);
  bunny_ini_set_field(ini, scope, "rot", 1, value);
  bunny_free(value);
  value = setnbr(sph->rot.z);
  bunny_ini_set_field(ini, scope, "rot", 2, value);
  bunny_free(value);
}

static	void	sphere_coef(t_sphere *sph,
			    t_bunny_ini *ini, char *scope)
{
  char		*value;

  value = setnbr(sph->ka * 100);
  bunny_ini_set_field(ini, scope, "ka", 0, value);
  bunny_free(value);
  value = setnbr(sph->kd * 100);
  bunny_ini_set_field(ini, scope, "kd", 0, value);
  bunny_free(value);
  value = setnbr(sph->ks * 100);
  bunny_ini_set_field(ini, scope, "ks", 0, value);
  bunny_free(value);
  value = setnbr(sph->brightness * 100);
  bunny_ini_set_field(ini, scope, "brightness", 0, value);
  bunny_free(value);
  value = setnbr(sph->reflection * 100);
  bunny_ini_set_field(ini, scope, "reflection", 0, value);
  bunny_free(value);
  value = setnbr(sph->opacity);
  bunny_ini_set_field(ini, scope, "opacity", 0, value);
  bunny_free(value);
}

void		sphere_obj(t_data *data, t_object *obj,
			   t_bunny_ini *ini, int i)
{
  char		*value;
  char		*scope;
  t_sphere	*sph;

  sph = obj->datas;
  scope = data->itfc.save.obj_names[i];
  bunny_ini_set_field(ini, scope, "type", 0, "sphere");
  sphere_pos(sph, ini, scope);
  sphere_rot(sph, ini, scope);
  bunny_ini_set_field(ini, scope, "real", 0, "1");
  value = setnbr(sph->tex_type);
  bunny_ini_set_field(ini, scope, "tex_type", 0, value);
  bunny_free(value);
  value = setnbr(sph->size);
  bunny_ini_set_field(ini, scope, "size", 0, value);
  bunny_free(value);
  sphere_coef(sph, ini, scope);
  value = put_base(sph->color.full, "0123456789ABCDEF");
  bunny_ini_set_field(ini, scope, "color", 0, value);
  bunny_free(value);
}
