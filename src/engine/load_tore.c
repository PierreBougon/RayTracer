/*
** load_tore.c for load_tore in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May 16 17:03:11 2016 benjamin duhieu
** Last update Sun May 22 17:36:28 2016 bougon_p
*/

#include "raytracer.h"

int		load_tore_datas1(t_tore *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing tore x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing tore y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing tore z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing tore x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing tore y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing tore z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rad", 0)) == NULL)
    return (my_puterr("load_datas: missing tore rad"));
  s->rad = (double)my_getnbr((char *)field);
  return (load_tore_datas2(s, ini, scope));
}

int		load_tore_datas2(t_tore *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "dist", 0)) == NULL)
    return (my_puterr("load_datas: missing tore dist"));
  s->dist = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing tore type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing tore ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing tore specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing tore brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing tore reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  return (load_tore_datas3(s, ini, scope));
}

int		load_tore_datas3(t_tore *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing tore opacity"));
  s->opacity = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing tore color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing tore color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing tore texture"));
      s->tex_name = my_strdup((char *)field);
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid tore texture1"));
    }
  else
    {
      s->tex_name = NULL;
      s->texture = NULL;
    }
  return (0);
}

int		load_tore(t_rt *rt,
			  t_bunny_ini *ini,
			  char *scope)
{
  t_object	*it;
  t_tore	*s;

  if ((s = bunny_malloc(sizeof(t_tore))) == NULL)
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
  it->type = TORE;
  if (load_tore_datas1(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  return (0);
}
