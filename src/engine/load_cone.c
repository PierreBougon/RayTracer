/*
** load_cone.c for load_cone in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 16:56:19 2016 romain samuel
** Last update Fri May 13 22:53:50 2016 bougon_p
*/

#include "raytracer.h"

int		load_cone_datas(t_cone *s,
				t_bunny_ini *ini,
				char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing cone x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing cone y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing cone z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing cone x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing cone y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing cone z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "height", 0)) == NULL)
    return (my_puterr("load_datas: missing cone height"));
  s->height = my_getnbr((char *)field);
  return (load_cone_datas2(s, ini, scope));
}

int		load_cone_datas2(t_cone *s, t_bunny_ini *ini, char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "angle", 0)) == NULL)
    return (my_puterr("load_datas: missing cone angle"));
  s->angle = 90 - my_getnbr((char *)field);
  if (s->angle >= 90 || s->angle <= 0)
    return (my_puterr("load_datas: invalid cone angle"));
  if ((field = bunny_ini_get_field(ini, scope, "real", 0)) == NULL)
    return (my_puterr("load_datas: missing cone type"));
  s->real = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "refraction", 0)) == NULL)
    return (my_puterr("load_datas: missing refraction"));
  s->refraction = atof((char *)field);
  if (s->real == 1)
    return (load_cone_datas3(s, ini, scope));
  else
    return (0);
}

int		load_cone_datas3(t_cone *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing cone ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing cone diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing cone specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing cone brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing cone reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing cone tex_type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing cone opacity"));
  s->opacity = my_getnbr((char *)field);
  return (load_cone_datas4(s, ini, scope));
}

int		load_cone_datas4(t_cone *s, t_bunny_ini *ini, char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing cone color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing cone color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  s->tex1_name = NULL;
  s->tex2_name = NULL;
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture1", 0)) == NULL)
	return (my_puterr("load_datas: missing cone texture1"));
      s->tex1_name = my_strdup((char *)field);
      if ((s->texture2 = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid cone texture1"));
      if ((field = bunny_ini_get_field(ini, scope, "texture2", 0)) == NULL)
	return (my_puterr("load_datas: missing cone texture2"));
      s->tex2_name = my_strdup((char *)field);
      if ((s->texture1 = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid cone texture2"));
    }
  return (0);
}

int		load_cone(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_cone	*s;

  if ((s = bunny_malloc(sizeof(t_cone))) == NULL)
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
  it->type = 3;
  if (load_cone_datas(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  return (0);
}
