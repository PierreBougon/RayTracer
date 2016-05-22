/*
** load_hyper.c for load_hyper in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri May 20 11:51:37 2016 benjamin duhieu
** Last update Sun May 22 17:35:08 2016 bougon_p
*/

#include "raytracer.h"

int		load_hyper_datas1(t_hyper *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "pos", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper x_pos"));
  s->pos.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 1)) == NULL)
    return (my_puterr("load_datas: missing hyper y_pos"));
  s->pos.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "pos", 2)) == NULL)
    return (my_puterr("load_datas: missing hyper z_pos"));
  s->pos.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper x_rot"));
  s->rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 1)) == NULL)
    return (my_puterr("load_datas: missing hyper y_rot"));
  s->rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "rot", 2)) == NULL)
    return (my_puterr("load_datas: missing hyper z_rot"));
  s->rot.z = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "a", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper a parameter"));
  s->a = (double)my_getnbr((char *)field);
  return (load_hyper_datas2(s, ini, scope));
}

int		load_hyper_datas2(t_hyper *s,
				 t_bunny_ini *ini,
				 char *scope)
{
  const	char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "b", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper b parameter"));
  s->b = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "c", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper c parameter"));
  s->c = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "nappe", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper nappe"));
  if ((s->nappe = my_getnbr((char *)field)) != 1 && s->nappe != 2)
    return (my_puterr("load_datas: nappe must be 1 or 2"));
  if ((field = bunny_ini_get_field(ini, scope, "tex_type", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper type"));
  s->tex_type = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, scope, "ka", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper ambient coef"));
  s->ka = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "kd", 0)) == NULL)
    return (my_puterr("load_datas: missing diffuse coef"));
  s->kd = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "ks", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper specular coef"));
  s->ks = (double)my_getnbr((char *)field) / 100;
  return (load_hyper_datas3(s, ini, scope, field));
}

int		load_hyper_datas3(t_hyper *s,
				  t_bunny_ini *ini,
				  char *scope,
				  const char *field)
{
  if ((field = bunny_ini_get_field(ini, scope, "brightness", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper brightness"));
  s->brightness = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "reflection", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper reflection"));
  s->reflection = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "opacity", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper opacity"));
  s->opacity = (double)my_getnbr((char *)field) / 100;
  if ((field = bunny_ini_get_field(ini, scope, "color1", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper color1"));
  s->color1.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if ((field = bunny_ini_get_field(ini, scope, "color2", 0)) == NULL)
    return (my_puterr("load_datas: missing hyper color2"));
  s->color2.full = my_getcolor((char *)field, "0123456789ABCDEF");
  if (s->tex_type == IMAGE)
    {
      if ((field = bunny_ini_get_field(ini, scope, "texture", 0)) == NULL)
	return (my_puterr("load_datas: missing hyper texture"));
      s->tex_name = my_strdup((char *)field);
      if ((s->texture = bunny_load_pixelarray((char *)field)) == NULL)
	return (my_puterr("load_datas: invalid hyper texture1"));
    }
  else
    {
      s->tex_name = NULL;
      s->texture = NULL;
    }
  return (0);
}

int		load_hyper(t_rt *rt,
			  t_bunny_ini *ini,
			  char *scope)
{
  t_object	*it;
  t_hyper	*s;

  if ((s = bunny_malloc(sizeof(t_hyper))) == NULL)
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
  it->type = HYPER;
  if (load_hyper_datas1(s, ini, scope) == -1)
    return (-1);
  it->datas = s;
  return (0);
}
