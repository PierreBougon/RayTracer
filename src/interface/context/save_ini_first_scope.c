/*
** save_ini_first_scope.c for ini in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 29 16:39:20 2016 bougon_p
** Last update Fri May 13 21:32:30 2016 bougon_p
*/

#include "raytracer.h"

static	void	set_first_scope_eye(t_data *data, t_bunny_ini *ini)
{
  char		*value;

  value = setnbr(data->rt.eye.pos.x);
  bunny_ini_set_field(ini, "RT", "eye_pos", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.pos.y);
  bunny_ini_set_field(ini, "RT", "eye_pos", 1, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.pos.z);
  bunny_ini_set_field(ini, "RT", "eye_pos", 2, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.rot.x);
  bunny_ini_set_field(ini, "RT", "eye_rot", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.rot.y);
  bunny_ini_set_field(ini, "RT", "eye_rot", 1, value);
  bunny_free(value);
  value = setnbr(data->rt.eye.rot.z);
  bunny_ini_set_field(ini, "RT", "eye_rot", 2, value);
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
  if ((data->itfc.save.obj_names = bunny_malloc(sizeof(char *) * 1)) == NULL)
    return (1);
  data->itfc.save.obj_names[0] = NULL;
  while (obj != NULL)
    {
      name = data->itfc.save.fct_save_ini_name
	[obj->type - 1 % NB_OBJ](data, i);
      bunny_ini_set_field(ini, "RT", "objs", i, name);
      save_name(data, name, i);
      obj = obj->next;
      i++;
    }
  return (0);
}

static	void	set_skybox(t_data *data, t_bunny_ini *ini)
{
  char		*value;

  value = setnbr(data->rt.opt.skybox);
  bunny_ini_set_field(ini, "RT", "skybox", 0, value);
  bunny_free(value);
  if (data->rt.opt.skybox != 0)
    {
      bunny_ini_set_field(ini, "RT", "sb_right", 0,
			  data->rt.opt.skybox_right_tex_name);
      bunny_ini_set_field(ini, "RT", "sb_left", 0,
			  data->rt.opt.skybox_left_tex_name);
      bunny_ini_set_field(ini, "RT", "sb_up", 0,
			  data->rt.opt.skybox_up_tex_name);
      bunny_ini_set_field(ini, "RT", "sb_down", 0,
			  data->rt.opt.skybox_down_tex_name);
      bunny_ini_set_field(ini, "RT", "sb_forward", 0,
			  data->rt.opt.skybox_front_tex_name);
      bunny_ini_set_field(ini, "RT", "sb_backward", 0,
			  data->rt.opt.skybox_back_tex_name);
    }
}

void		set_first_scope(t_data *data, t_bunny_ini *ini)
{
  char		*value;

  set_first_scope_obj(data, ini);
  set_first_scope_eye(data, ini);
  value = setnbr((int)(data->rt.opt.ambient * 100));
  bunny_ini_set_field(ini, "RT", "ambiant_lum", 0, value);
  bunny_free(value);
  value = setnbr((int)(data->rt.opt.ambient * 100));
  bunny_ini_set_field(ini, "RT", "ambiant_lum", 0, value);
  bunny_free(value);
  value = setnbr((int)(data->rt.opt.ambient_refraction));
  bunny_ini_set_field(ini, "RT", "ambient_refraction", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.opt.aa);
  bunny_ini_set_field(ini, "RT", "supersampling", 0, value);
  bunny_free(value);
  value = setnbr(data->rt.opt.ss);
  bunny_ini_set_field(ini, "RT", "soft_shadows", 0, value);
  bunny_free(value);
  if (data->rt.opt.ss == 1)
    {
      value = setnbr(data->rt.opt.nb_rays_ss);
      bunny_ini_set_field(ini, "RT", "nb_rays_ss", 0, value);
      bunny_free(value);
      value = setnbr(data->rt.opt.ray_ss);
      bunny_ini_set_field(ini, "RT", "ray_ss", 0, value);
      bunny_free(value);
    }
  set_skybox(data, ini);
}
