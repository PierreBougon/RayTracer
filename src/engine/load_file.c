/*
** load_file.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:28:05 2016 romain samuel
** Last update Sun Apr 10 22:30:51 2016 romain samuel
*/

#include "raytracer.h"

int		load_type(t_rt *s,
			  t_bunny_ini *ini,
			  int (**ftab)(t_rt *rt, t_bunny_ini *ini,
				       char *scope),
			  char *scope)
{
  char		*tab[5];
  int		i;
  const char	*field;

  i = -1;
  tab[0] = my_strdup("sphere");
  tab[1] = my_strdup("cone");
  tab[2] = my_strdup("cylinder");
  tab[3] = my_strdup("plan");
  tab[4] = my_strdup("light");
  while (++i < 5)
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

  if ((ftab = malloc(sizeof(ftab) * 5)) == NULL)
    return (my_puterr("load_object: malloc failed"));
  ftab[0] = &load_sphere;
  ftab[1] = &load_cone;
  ftab[2] = &load_cylinder;
  ftab[3] = &load_plan;
  ftab[4] = &load_light;
  if (load_type(s, ini, ftab, scope) == -1)
    return (-1);
  return (0);
}

int		load_eye(t_rt *s, t_bunny_ini *ini)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "eye_pos", 0)) == NULL)
    return (my_puterr("load_eye: missing eye xpos"));
  s->eye.pos.x = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "eye_pos", 1)) == NULL)
    return (my_puterr("load_eye: missing eye ypos"));
  s->eye.pos.y = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "eye_pos", 2)) == NULL)
    return (my_puterr("load_eye: missing eye zpos"));
  s->eye.pos.z = (double)my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "eye_rot", 0)) == NULL)
    return (my_puterr("load_eye: missing eye xrot"));
  s->eye.rot.x = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "eye_rot", 1)) == NULL)
    return (my_puterr("load_eye: missing eye yrot"));
  s->eye.rot.y = my_getnbr((char *)field);
  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "eye_rot", 2)) == NULL)
    return (my_puterr("load_eye: missing eye zrot"));
  s->eye.rot.z = my_getnbr((char *)field);
  return (0);
}

int		load_scene_parameters(t_rt *s, t_bunny_ini *ini)
{
  const char	*field;
  double	aa;

  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "ambiant_lum", 0))
      == NULL)
    return (my_puterr("load_file: missing ambiant_lum"));
  s->opt.ambient = (double)my_getnbr((char *)field) / 100.0;
  if ((field = bunny_ini_get_field(ini, "RAYTRACER", "supersampling", 0))
      == NULL)
    return (my_puterr("load_file: missing supersampling coef"));
  s->opt.aa = my_getnbr((char *)field);
  aa = sqrt(s->opt.aa);
  if (aa != (int)aa)
    return (my_puterr("load_file: invalid antialiasing settings"));
  return (0);
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
  while ((field = bunny_ini_get_field(ini, "RAYTRACER", "objs", i)) != NULL)
    {
      if (load_object(s, ini, (char *)field) == -1)
	return (-1);
      i++;
    }
  s->obj_hit = NULL;
  return (0);
}
