/*
** load_csg.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue May 10 18:11:07 2016 romain samuel
** Last update Sun May 22 21:52:57 2016 romain samuel
*/

#include "raytracer.h"

int		load_csg_type(t_rt *rt,
			      t_csg *node,
			      t_bunny_ini *ini,
			      char *scope)
{
  char		*tab[6];
  int		i;
  const char	*field;
  int		(**ftab)(t_rt *rt, t_csg *node, t_bunny_ini *ini, char *scope);

  if ((ftab = bunny_malloc(sizeof(ftab) * 4)) == NULL)
    return (my_puterr("load_object: malloc failed"));
  ftab[0] = &load_csg_sphere;
  ftab[1] = &load_csg_cylinder;
  ftab[2] = &load_csg_cone;
  ftab[3] = &load_csg_box;
  i = -1;
  if ((tab[0] = my_strdup("sphere")) == NULL ||
      (tab[1] = my_strdup("cylinder")) == NULL ||
      (tab[2] = my_strdup("cone")) == NULL ||
      (tab[3] = my_strdup("box")) == NULL)
    return (-1);
  while (++i < 4)
    {
      if ((field = bunny_ini_get_field(ini, scope, "type", 0)) == NULL)
	return (my_puterr("Could not perform bunny_ini_get_field"));
      if (my_strcmp((char *)field, tab[i]) == 0)
	return (ftab[i](rt, node, ini, scope));
    }
  return (0);
}

int		load_csg_object(t_rt *rt,
				t_csg *node,
				t_bunny_ini *ini,
				char *scope)
{
  if (load_csg_type(rt, node, ini, scope) == -1)
    return (-1);
  return (0);
}

int		load_leaf(t_rt *rt,
			  t_csg *node,
			  char *scope,
			  t_bunny_ini *ini)
{
  const char	*field;

  if ((field = bunny_ini_get_field(ini, scope, "type", 0)) == NULL)
    return (my_puterr("load_datas: missing csg node type"));
  node->type = my_getnbr((char *)field);
  if (node->type > 0 && node->type < 4)
    {
      if (!(field = bunny_ini_get_field(ini, scope, "connections", 0)))
	return (my_puterr("load_datas: missing csg node connections"));
      node->connections[0] = my_getnbr((char *)field);
      if (!(field = bunny_ini_get_field(ini, scope, "connections", 1)))
	return (my_puterr("load_datas: missing csg node connections"));
      node->connections[1] = my_getnbr((char *)field);
    }
  else if (node->type == 0)
    {
      if ((field = bunny_ini_get_field(ini, scope, "object", 0)) == NULL)
	return (my_puterr("load_datas: missing csg node object"));
      if (load_csg_object(rt, node, ini, (char *)field) == -1)
	return (my_puterr("load_datas: could not load_object"));
    }
  else
    return (-1);
  return (0);
}

t_csg		*load_csg_datas(t_rt *rt,
				t_bunny_ini *ini,
				char *scope)
{
  const char	*field;
  t_csg		**tab;
  t_csg		*csg;
  int		nodes;
  int		i;

  i = 0;
  if ((field = bunny_ini_get_field(ini, scope, "nb_nodes", 0)) == NULL)
    return (my_puterror("load_datas: missing csg node_nb"));
  if ((nodes = my_getnbr((char *)field)) == -1)
    return (my_puterror("load_datas: invalid csg"));
  if ((tab = create_csg_tab(nodes)) == NULL)
    return (my_puterror("Could not perform bunny_malloc"));
  while (i < nodes)
    {
      if ((field = bunny_ini_get_field(ini, scope, "nodes", i)) == NULL)
	return (my_puterror("load_datas: invalid nodes"));
      if (load_leaf(rt, tab[i], (char *)field, ini) == -1)
	return (my_puterror("load_datas: could not load leaf"));
      i++;
    }
  if (create_csg_tree(tab, nodes) == -1)
    return (my_puterror("load_dats: could not create csg"));
  csg = tab[0];
  return (csg);
}

int		load_csg(t_rt *rt, t_bunny_ini *ini, char *scope)
{
  t_object	*it;
  t_csg		*s;

  if ((s = bunny_malloc(sizeof(t_csg))) == NULL)
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
  it->type = CSG;
  if ((s = load_csg_datas(rt, ini, scope)) == NULL)
    return (-1);
  it->datas = s;
  if ((it->name = my_strdup(scope)) == NULL)
    return (my_puterr("Could not perform malloc"));
  return (0);
}
