/*
** load_other.c for load_other.c
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun May 22 17:36:17 2016 benjamin duhieu
** Last update Sun May 22 21:39:43 2016 benjamin duhieu
*/

#include "raytracer.h"

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
  if (!(s->opt.skybox_forward = bunny_load_pixelarray((char *)field)))
    return (my_puterr("load_datas: invalid skybox forward texture"));
  if ((field = bunny_ini_get_field(ini, "RT", "sb_backward", 0)) == NULL)
    return (my_puterr("load_datas: missing skybox backward texture"));
  s->opt.skybox_back_tex_name = my_strdup((char *)field);
  if (!(s->opt.skybox_backward = bunny_load_pixelarray((char *)field)))
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
    return (s->opt.skybox = 0);
  s->opt.skybox = my_getnbr((char *)field);
  return (load_skybox_textures(s, ini, field));
}
