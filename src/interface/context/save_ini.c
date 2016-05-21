/*
** save_ini.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 17:07:33 2016 bougon_p
** Last update Tue May 17 18:20:36 2016 bougon_p
*/

#include "raytracer.h"

static char	*create_ini_name(t_data *data)
{
  char			*name;

  name = my_strdup("assets/scenes/");
  name = myrealloc(name, my_strlen(data->itfc.save.file));
  my_strcat(name, data->itfc.save.file);
  return (name);
}

static void	set_objs_scopes(t_object *obj,
				t_data *data, t_bunny_ini *ini)
{
  int		i;

  i = 0;
  while (obj != NULL)
    {
      data->itfc.save.fct_save_ini_obj
	[obj->type](data, obj, ini, i);
      obj = obj->next;
      i++;
    }
}

void		save_new_ini(t_data *data)
{
  t_bunny_ini	*ini;
  char		*name;
  t_object	*act_obj;

  ini = bunny_new_ini();
  name = create_ini_name(data);
  set_first_scope(data, ini);
  act_obj = data->rt.obj;
  set_objs_scopes(act_obj, data, ini);
  bunny_save_ini(ini, name);
  bunny_free(name);
  free_tab(data->itfc.save.obj_names);
}
