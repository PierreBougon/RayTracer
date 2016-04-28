/*
** load_cylinder.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 16:47:06 2016 romain samuel
** Last update Mon Apr 25 18:11:12 2016 romain samuel
*/

#include "raytracer.h"

int		load_cylinder_datas(t_cylinder *s,
				  t_bunny_ini *ini,
				  char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing cylinder y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing cylinder z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing cylinder y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing cylinder z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "height", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder height"));
  s->height = my_getnbr((char *)field);
  return (load_cylinder_datas2(s, ini, scope));
}

int		load_cylinder_datas2(t_cylinder *s, t_bunny_ini *ini, char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "size", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder size"));
  s->size = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "real", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder type"));
  s->real = my_getnbr((char *)field);
  if (s->real == 1)
    return (load_cylinder_datas3(s, ini, scope));
  else
    return (0);
}

int		load_cylinder_datas3(t_cylinder *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder tex_type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing cylinder opacity"));
  s->opacity = my_getnbr((char *)field);
  return (load_cylinder_datas4(s, ini, scope));
}

int		load_cylinder_datas4(t_cylinder *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "refraction", 0)) == NULL)
    return (my_puterr("load_datas: missing refraction"));
  s->refraction = atof((char *)field);
  if (s->tex_type != IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
	return (my_puterr("load_datas: missing cylinder color1"));
      s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
      if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
	return (my_puterr("load_datas: missing cylinder color2"));
      s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
    }
  else
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing cylinder texture"));
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (-1);
    }
  return (0);
}

int		load_cylinder(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_cylinder	*s;

  if ((s = malloc(sizeof(t_cylinder))) == NULL)
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
  it->type = 2;
  load_cylinder_datas(s, ini, scope);
  it->datas = s;
  return (0);
}
