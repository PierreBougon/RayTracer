/*
** save_ini.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 17:07:33 2016 bougon_p
** Last update Fri Apr 29 01:55:26 2016 bougon_p
*/

#include "raytracer.h"

static char	*create_ini_name(t_data *data)
{
  char			*name;

  name = my_strdup("assets/scenes/");
  printf("%s\n", name);
  name = myrealloc(name, my_strlen(data->itfc.save.file) + 1000);
  printf("%s\n", name);
  my_strcat(name, data->itfc.save.file);
  printf("%s\n", name);
  return (name);
}

static	void	set_first_scope_eye(t_data *data, t_bunny_ini *ini)
{
  char		*value;

  value = setnbr(data->rt.eye.pos.x);
  bunny_ini_set_field(ini, "RAYTRACER", "eye_pos", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.pos.y);
  bunny_ini_set_field(ini, "RAYTRACER", "eye_pos", 1, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.pos.z);
  bunny_ini_set_field(ini, "RAYTRACER", "eye_pos", 2, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.rot.x);
  bunny_ini_set_field(ini, "RAYTRACER", "eye_rot", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.rot.y);
  bunny_ini_set_field(ini, "RAYTRACER", "eye_rot", 1, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.rot.z);
  bunny_ini_set_field(ini, "RAYTRACER", "eye_rot", 2, value);
  bunny_free(value);
}

static	void	save_name(t_data *data, char *name, int i)
{
  data->itfc.save.obj_names =
    my_realloc_tab(data->itfc.save.obj_names, 1);
  data->itfc.save.obj_names[i] = name;
}

static	int	set_first_scope_obj(t_data *data, t_bunny_ini *ini)
{
  int		i;
  char		*name;
  t_object	*obj;

  obj = data->rt.obj;
  i = 0;
  if ((data->itfc.save.obj_names = malloc(sizeof(char *) * 1)) == NULL)
    return (1);
  data->itfc.save.obj_names[0] = NULL;
  while (obj->next != NULL)
    {
      name = data->itfc.save.fct_save_ini_name
	[obj->type - 1 % NB_OBJ](data, i);
      bunny_ini_set_field(ini, "RAYTRACER", "objs", i, name);
      save_name(data, name, i);
      obj = obj->next;
      i++;
    }
  name = data->itfc.save.fct_save_ini_name
    [obj->type - 1 % NB_OBJ](data, i);
  bunny_ini_set_field(ini, "RAYTRACER", "objs", i, name);
  save_name(data, name, i);
  return (0);
}

static	void	set_first_scope(t_data *data, t_bunny_ini *ini)
{
  char		*value;

  set_first_scope_obj(data, ini);
  set_first_scope_eye(data, ini);
  value = setnbr((int)(data->rt.opt.ambient * 100));
  bunny_ini_set_field(ini, "RAYTRACER", "ambiant_lum", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.opt.aa);
  bunny_ini_set_field(ini, "RAYTRACER", "supersampling", 0, value);
  bunny_free(value);
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
  bunny_save_ini(ini, name);
  free(name);


  int	i;
  i = -1;
  printf("##PRINT DEBUG NAMES\n\n");
  while (data->itfc.save.obj_names[++i] != NULL)
    {
      printf("%s\n", data->itfc.save.obj_names[i]);
    }
}
