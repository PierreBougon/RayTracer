/*
** create_csg_tree.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon May 16 16:48:46 2016 romain samuel
** Last update Sat May 21 07:46:48 2016 romain samuel
*/

#include "raytracer.h"

int	check_csg_integrity(t_csg *it)
{
  if ((it->id != 1 && it->up == NULL) ||
      (it->type != 0 && (it->left == NULL || it->right == NULL)))
    return (-1);
  if (it->left != NULL && it->left != it)
    if (check_csg_integrity(it->left) == -1)
      return (-1);
  if (it->right != NULL && it->right != it)
    if (check_csg_integrity(it->right) == -1)
      return (-1);
  return (0);
}

int	link_nodes(t_csg **tab, int i, int nb)
{
  if (tab[i]->connections[0] < 1 || tab[i]->connections[0] > nb ||
      tab[i]->connections[1] < 1 || tab[i]->connections[1] > nb)
    return (my_puterr("could not link csg nodes: invalid connections"));
  if (tab[i]->connections[0] == i + 1 || tab[i]->connections[1] == i + 1)
    return (my_puterr("could not link csg nodes: don't connect a node to itself you scrublord"));
  if (tab[i]->left != NULL || tab[i]->right != NULL ||
      tab[tab[i]->connections[0] - 1]->up != NULL ||
      tab[tab[i]->connections[1] - 1]->up != NULL)
    return (my_puterr("could not link csg nodes: node connected two times"));
  tab[i]->left = tab[tab[i]->connections[0] - 1];
  tab[i]->right = tab[tab[i]->connections[1] - 1];
  tab[tab[i]->connections[0] - 1]->up = tab[i];
  tab[tab[i]->connections[1] - 1]->up = tab[i];
  return (0);
}

int	create_csg_tree(t_csg **tab, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      if (tab[i]->type != 0)
	if (link_nodes(tab, i, nb) == -1)
	  return (-1);
      i++;
    }
  if (check_csg_integrity(tab[0]) == -1)
    return (-1);
  init_tree_inters(tab[0]);
  return (0);
}
