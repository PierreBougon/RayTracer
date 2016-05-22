/*
** load_box.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Wed May  4 15:28:11 2016 romain samuel
** Last update Sun May 22 17:33:03 2016 bougon_p
*/

#include "raytracer.h"

int		load_box_datas(t_box *s,
			       t_bunny_ini *ini,
			       char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing box x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing box y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing box z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing box x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing box y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing box z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing box reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  return (load_box_datas2(s, ini, scope));
}

int		load_box_datas2(t_box *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "size", 0)) == NULL)
    return (my_puterr("load_datas: missing box x_size"));
  s->size.x = my_getnbr((char *)field) / 2;
  if ((field = bunny_ini_get_field(ini, scope, "size", 1)) == NULL)
    return (my_puterr("load_datas: missing box y_size"));
  s->size.y = my_getnbr((char *)field) / 2;
  if ((field = bunny_ini_get_field(ini, scope, "size", 2)) == NULL)
    return (my_puterr("load_datas: missing box z_size"));
  s->size.z = my_getnbr((char *)field) / 2;
  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing box ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing box diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing box specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing box brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing box opacity"));
  s->opacity = (double)my_getnbr((char *)field) / 100;
  return (load_box_datas3(s, ini, scope));
}

int		load_box_datas3(t_box *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "refraction", 0)) == NULL)
    return (my_puterr("load_datas: missing box refraction"));
  s->refraction = atof((char *)field);
  return (load_box_datas4(s, ini, scope));
}

int		load_box_datas4(t_box *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing box tex_type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing box color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing box color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing box texture"));
      s->tex_name = my_strdup((char *)field);
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid box texture"));
    }
  else
    {
      s->tex_name = NULL;
      s->texture = NULL;
    }
  return (0);
}

int		load_box(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_box		*s;

  if ((s = bunny_malloc(sizeof(t_box))) == NULL)
    return (-1);
  if (rt->obj == NULL)
    {
      if ((rt->obj = create_obj_list()) == NULL)
	return (-1);
    }
  else
    if (add_obj_elem(rt->obj) == -1)
      return (-1);
  it = rt->obj;
  while (it->next != NULL)
    it = it->next;
  it->type = 6;
  if (load_box_datas(s, ini, scope) == -1)
    return (-1);
  if (load_plan_sides(rt, s) == -1)
    return (-1);
  it->datas = s;
  if ((it->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}
