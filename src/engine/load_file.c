/*
** load_file.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:28:05 2016 romain samuel
** Last update Sun May 22 17:36:04 2016 benjamin duhieu
*/

#include "raytracer.h"

int		load_type(t_rt *s,
			  t_bunny_ini *ini,
			  int (**ftab)(t_rt *rt, t_bunny_ini *ini,
				       char *scope),
			  char *scope)
{
  char		*tab[NB_OBJ + 1];
  int		i;
  const char	*field;

  i = -1;
  tab[0] = "sphere";
  tab[1] = "cylinder";
  tab[2] = "cone";
  tab[3] = "plan";
  tab[4] = "light";
  tab[5] = "box";
  tab[6] = "csg";
  tab[7] = "tore";
  tab[8] = "hole_cube";
  tab[9] = "hyper";
  tab[10] = "parab";
  tab[11] = "ellip";
  while (++i < NB_OBJ + 1)
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

  if ((ftab = bunny_malloc(sizeof(ftab) * (NB_OBJ + 1))) == NULL)
    return (my_puterr("load_object: malloc failed"));
  ftab[0] = &load_sphere;
  ftab[1] = &load_cylinder;
  ftab[2] = &load_cone;
  ftab[3] = &load_plan;
  ftab[4] = &load_light;
  ftab[5] = &load_box;
  ftab[6] = &load_csg;
  ftab[7] = &load_tore;
  ftab[8] = &load_hole_cube;
  ftab[9] = &load_hyper;
  ftab[10] = &load_parab;
  ftab[11] = &load_ellip;
  if (load_type(s, ini, ftab, scope) == -1)
    return (-1);
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
  while ((field = bunny_ini_get_field(ini, "RT", "objs", i)) != NULL)
    {
      if (load_object(s, ini, (char *)field) == -1)
	return (-1);
      i++;
    }
  s->obj_hit = NULL;
  return (0);
}
