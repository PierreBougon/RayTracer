/*
** load_hole_cube.c for hole_cube
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu May 19 22:00:37 2016 benjamin duhieu
** Last update Sun May 22 21:39:10 2016 benjamin duhieu
*/

#include "raytracer.h"

int		load_hole_cube_datas1(t_hole_cube *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing hole_cube y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing hole_cube z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing hole_cube y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing hole_cube z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rad", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube rad"));
  s->rad = (double)my_getnbr((char *)field);
  return (load_hole_cube_datas2(s, ini, scope));
}

int		load_hole_cube_datas2(t_hole_cube *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  return (load_hole_cube_datas3(s, ini, scope));
}

int		load_hole_cube_datas3(t_hole_cube *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube opacity"));
  s->opacity = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing hole_cube color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  s->tex_name = NULL;
  s->texture = NULL;
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing hole_cube texture"));
      s->tex_name = my_strdup((char *)field);
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid hole_cube texture1"));
    }
  return (0);
}

int		load_hole_cube(t_rt *rt,
			  t_bunny_ini *ini,
			  char *scope)
{
  t_object	*it;
  t_hole_cube	*s;

  if ((s = bunny_malloc(sizeof(t_hole_cube))) == NULL)
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
  it->type = HOLE_CUBE;
  if (load_hole_cube_datas1(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  return (0);
}
