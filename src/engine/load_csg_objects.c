/*
** load_csg_objects.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat May 14 19:53:45 2016 romain samuel
** Last update Sun May 22 21:38:54 2016 benjamin duhieu
*/

#include "raytracer.h"

int		load_csg_sphere(t_rt *rt,
				t_csg *node,
				t_bunny_ini *ini,
				char *scope)
{
  t_sphere	*s;

  (void)rt;
  if ((node->obj = bunny_malloc(sizeof(t_object))) == NULL)
    return (my_puterr("Could not perform malloc"));
  if ((s = bunny_malloc(sizeof(t_sphere))) == NULL)
    return (my_puterr("Could not perform malloc"));
  node->obj->type = 2;
  if (load_sphere_datas(s, ini, scope) == -1)
    return (-1);
  node->obj->datas = s;
  if ((node->obj->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}

int		load_csg_cylinder(t_rt *rt,
				  t_csg *node,
				  t_bunny_ini *ini,
				  char *scope)
{
  t_cylinder	*s;

  (void)rt;
  if ((node->obj = bunny_malloc(sizeof(t_object))) == NULL)
    return (my_puterr("Could not perform malloc"));
  if ((s = bunny_malloc(sizeof(t_cylinder))) == NULL)
    return (my_puterr("Could not perform malloc"));
  node->obj->type = 3;
  if (load_cylinder_datas(s, ini, scope) == -1)
    return (-1);
  node->obj->datas = s;
  if ((node->obj->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}

int		load_csg_cone(t_rt *rt,
			      t_csg *node,
			      t_bunny_ini *ini,
			      char *scope)
{
  t_cone	*s;

  (void)rt;
  if ((node->obj = bunny_malloc(sizeof(t_object))) == NULL)
    return (my_puterr("Could not perform malloc"));
  if ((s = bunny_malloc(sizeof(t_cone))) == NULL)
    return (my_puterr("Could not perform malloc"));
  node->obj->type = 4;
  if (load_cone_datas(s, ini, scope) == -1)
    return (-1);
  node->obj->datas = s;
  if ((node->obj->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}

int		load_csg_box(t_rt *rt,
			     t_csg *node,
			     t_bunny_ini *ini,
			     char *scope)
{
  t_box		*s;

  if ((node->obj = bunny_malloc(sizeof(t_object))) == NULL)
    return (my_puterr("Could not perform malloc"));
  if ((s = bunny_malloc(sizeof(t_box))) == NULL)
    return (my_puterr("Could not perform malloc"));
  node->obj->type = 6;
  if (load_box_datas(s, ini, scope) == -1)
    return (-1);
  if (load_plan_sides(rt, s) == -1)
    return (-1);
  node->obj->datas = s;
  if ((node->obj->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}
