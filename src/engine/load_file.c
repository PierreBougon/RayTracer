/*
** load_file.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:28:05 2016 romain samuel
** Last update Mon May 16 17:00:53 2016 benjamin duhieu
*/

#include "raytracer.h"

int		load_type(t_rt *s,
			  t_bunny_ini *ini,
			  int (**ftab)(t_rt *rt, t_bunny_ini *ini,
				       char *scope),
			  char *scope)
{
  char		*tab[7];
  int		i;
  const char	*field;

  i = -1;
  tab[0] = my_strdup("light");
  tab[1] = my_strdup("sphere");
  tab[2] = my_strdup("cylinder");
  tab[3] = my_strdup("cone");
  tab[4] = my_strdup("plan");
  tab[5] = my_strdup("box");
  tab[6] = my_strdup("tore");
  while (++i < 7)
    {
      if ((field = bunny_ini_get_field(ini, scope, "type", 0)) == NULL)
	return (my_puterr("Could not perform bunny_ini_get_field"));
      if (my_strcmp((char *)field, tab[i]) == 0)
	return (ftab[i](s, ini, scope));
    }
  return (0);
}

int		load_object(t_rt *s, t_bunny_ini *ini, char *scope)
{
  int		(**ftab)(t_rt *s, t_bunny_ini *ini, char *scope);

  if ((ftab = bunny_malloc(sizeof(ftab) * 7)) == NULL)
    return (my_puterr("load_object: malloc failed"));
  ftab[0] = &load_light;
  ftab[1] = &load_sphere;
  ftab[2] = &load_cylinder;
  ftab[3] = &load_cone;
  ftab[4] = &load_plan;
  ftab[5] = &load_box;
  ftab[6] = &load_tore;
  if (load_type(s, ini, ftab, scope) == -1)
    return (-1);
  return (0);
}

int		load_eye(t_rt *s, t_bunny_ini *ini)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, "RT", "eye_pos", 0)) == NULL)
    return (my_puterr("load_eye: missing eye xpos"));
  s->eye.pos.x = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RT", "eye_pos", 1)) == NULL)
    return (my_puterr("load_eye: missing eye ypos"));
  s->eye.pos.y = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RT", "eye_pos", 2)) == NULL)
    return (my_puterr("load_eye: missing eye zpos"));
  s->eye.pos.z = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RT", "eye_rot", 0)) == NULL)
    return (my_puterr("load_eye: missing eye xrot"));
  s->eye.rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RT", "eye_rot", 1)) == NULL)
    return (my_puterr("load_eye: missing eye yrot"));
  s->eye.rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RT", "eye_rot", 2)) == NULL)
    return (my_puterr("load_eye: missing eye zrot"));
  s->eye.rot.z = my_getnbr((char *)field);
  return (0);
}

int		load_skybox_textures2(t_rt *s,
				      t_bunny_ini *ini,
				      const char *field)
{
  if ((field = bunny_ini_get_field(ini, "RT", "sb_down", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox down texture"));
  s->opt.skybox_down_tex_name = my_strdup((char *)field);
  if ((s->opt.skybox_down = bunny_load_pixelarray((char *)field)) == NULL)
    return (my_puterr("load_datas: invalid skybox down texture"));
  if ((field = bunny_ini_get_field(ini, "RT", "sb_forward", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox forward texture"));
  s->opt.skybox_front_tex_name = my_strdup((char *)field);
  if ((s->opt.skybox_forward = bunny_load_pixelarray((char *)field)) == NULL)
    return (my_puterr("load_datas: invalid skybox forward texture"));
  if ((field = bunny_ini_get_field(ini, "RT", "sb_backward", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox backward texture"));
  s->opt.skybox_back_tex_name = my_strdup((char *)field);
  if ((s->opt.skybox_backward = bunny_load_pixelarray((char *)field)) == NULL)
    return (my_puterr("load_datas: invalid skybox backward texture"));
  return (0);
}

int		load_skybox_textures(t_rt *s,
				     t_bunny_ini *ini,
				     const char *field)
{
  if ((field = bunny_ini_get_field(ini, "RT", "sb_right", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox right texture"));
  s->opt.skybox_right_tex_name = my_strdup((char *)field);
  if ((s->opt.skybox_right = bunny_load_pixelarray((char *)field)) == NULL)
    return (my_puterr("load_datas: invalid skybox right texture"));
  if ((field = bunny_ini_get_field(ini, "RT", "sb_left", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox left texture"));
  s->opt.skybox_left_tex_name = my_strdup((char *)field);
  if ((s->opt.skybox_left = bunny_load_pixelarray((char *)field)) == NULL)
    return (my_puterr("load_datas: invalid skybox left texture"));
  if ((field = bunny_ini_get_field(ini, "RT", "sb_up", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox up texture"));
  s->opt.skybox_up_tex_name = my_strdup((char *)field);
  if ((s->opt.skybox_up = bunny_load_pixelarray((char *)field)) == NULL)
    return (my_puterr("load_datas: invalid skybox up texture"));
  return (load_skybox_textures2(s, ini, field));
}

int		load_shadow_params(t_rt *s, t_bunny_ini *ini)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, "RT", "soft_shadows", 0))
      == NULL)
    return (my_puterr("load_file: missing soft_shadows attribute"));
  s->opt.ss = my_getnbr((char *)field);
  if (s->opt.ss == 1)
    {
      if ((field = bunny_ini_get_field(ini, "RT", "nb_rays_ss", 0))
	  == NULL)
	return (my_puterr("load_file: missing soft shadows ray number"));
      s->opt.nb_rays_ss = my_getnbr((char *)field);
      if ((field = bunny_ini_get_field(ini, "RT", "ray_ss", 0)) == NULL)
	return (my_puterr("load_file: missing soft_shadows ray_ss"));
      s->opt.ray_ss = my_getnbr((char *)field);
    }
  else
    {
      s->opt.nb_rays_ss = 1;
      s->opt.ray_ss = 0;
    }
  return (0);
}

int		load_scene_parameters(t_rt *s, t_bunny_ini *ini)
{
  const char	*field;
  double	aa;

  if (load_shadow_params(s, ini) == -1)
    return (-1);
  if ((field = bunny_ini_get_field(ini, "RT", "ambiant_lum", 0)) == NULL)
    return (my_puterr("load_file: missing ambiant_lum"));
  s->opt.ambient = (double)my_getnbr((char *)field) / 100.0;
  if ((field = bunny_ini_get_field(ini, "RT", "supersampling", 0))
      == NULL)
    return (my_puterr("load_file: missing supersampling coef"));
  s->opt.aa = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RT", "ambient_refraction", 0))
      == NULL)
    return (my_puterr("load_file: missing ambient_refraction"));
  s->opt.ambient_refraction = atof((char *)field);
  aa = sqrt(s->opt.aa);
  if (aa != (int)aa)
    return (my_puterr("load_file: invalid antialiasing settings"));
  if ((field = bunny_ini_get_field(ini, "RT", "skybox", 0)) == NULL)
    {
      s->opt.skybox = 0;
      return (0);
    }
  s->opt.skybox = my_getnbr((char *)field);
  return (load_skybox_textures(s, ini, field));
}

int		load_file(t_rt *s, char *file)
{
  t_bunny_ini	*ini;
  const char	*field;
  int		i;

  i = 0;
  s->obj = NULL;
  if ((ini = bunny_load_ini(file)) == NULL)
    return (my_puterr("Could not perform bunny_load_ini"));
  if (load_eye(s, ini) == -1)
    return (-1);
  if (load_scene_parameters(s, ini) == -1)
    return (-1);
  while ((field = bunny_ini_get_field(ini, "RT", "objs", i)) != NULL)
    {
      if (load_object(s, ini, (char *)field) == -1)
	return (-1);
      i++;
    }
  s->obj_hit = NULL;
  return (0);
}
