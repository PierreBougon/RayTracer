/*
** load_sphere.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:44:39 2016 romain samuel
** Last update Sat May 14 19:59:51 2016 romain samuel
*/

#include "raytracer.h"

int		load_sphere_datas(t_sphere *s,
				  t_bunny_ini *ini,
				  char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing sphere y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing sphere z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing sphere y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing sphere z_rot"));
  s->rot.z = my_getnbr((char *)field);
  return (load_sphere_datas2(s, ini, scope));
}

int		load_sphere_datas2(t_sphere *s, t_bunny_ini *ini, char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "size", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere size"));
  s->size = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "real", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere type"));
  s->real = my_getnbr((char *)field);
  if (s->real == 1)
    return (load_sphere_datas3(s, ini, scope));
  else
    return (0);
}

int		load_sphere_datas3(t_sphere *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere tex_type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere opacity"));
  s->opacity = my_getnbr((char *)field);
  return (load_sphere_datas4(s, ini, scope));
}

int		load_sphere_datas4(t_sphere *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "refraction", 0)) == NULL)
    return (my_puterr("load_datas: missing refraction"));
  s->refraction = atof((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing sphere color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing sphere texture"));
      s->tex_name = my_strdup((char *)field);
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid sphere texture"));
    }
  return (0);
}

int		load_sphere(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_sphere	*s;

  if ((s = bunny_malloc(sizeof(t_sphere))) == NULL)
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
  if (load_sphere_datas(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  if ((it->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}
