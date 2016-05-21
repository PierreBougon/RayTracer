/*
** load_plan.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 17:03:56 2016 romain samuel
** Last update Sat May 21 22:15:11 2016 romain samuel
*/

#include "raytracer.h"

int		load_plan_datas(t_plan *s,
				t_bunny_ini *ini,
				char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing plan x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing plan y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing plan z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing plan x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing plan y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing plan z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing plan reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  return (load_plan_datas2(s, ini, scope));
}

int		load_plan_datas2(t_plan *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "height", 0)) == NULL)
    return (my_puterr("load_datas: missing plan height"));
  s->height = my_getnbr((char *)field) / 2;
  if ((field = bunny_ini_get_field(ini, scope, "width", 0)) == NULL)
    return (my_puterr("load_datas: missing plan width"));
  s->width = my_getnbr((char *)field) / 2;
  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing plan ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing plan diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing plan specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing plan brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing plan opacity"));
  s->opacity = (double)my_getnbr((char *)field) / 100;
  return (load_plan_datas3(s, ini, scope));
}

int		load_plan_datas3(t_plan *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "refraction", 0)) == NULL)
    return (my_puterr("load_datas: missing refraction"));
  s->refraction = atof((char *)field);
  return (load_plan_datas4(s, ini, scope));
}

int		load_plan_datas4(t_plan *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing plan tex_type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing plan color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing plan color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "case_size", 0)) == NULL)
    return (my_puterr("load_datas: missing plan case_size"));
  s->case_size = my_getnbr((char *)field);
  s->tex_name = NULL;
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing plan texture"));
      s->tex_name = my_strdup((char *)field);
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid plan texture"));
    }
  return (0);
}

int		load_plan(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_plan	*s;

  if ((s = bunny_malloc(sizeof(t_plan))) == NULL)
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
  it->type = 4;
  if (load_plan_datas(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  if ((it->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}
