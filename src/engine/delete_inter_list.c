/*
** delete_inter_list.c for RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat May 21 06:34:30 2016 romain samuel
** Last update Sun May 22 21:34:05 2016 benjamin duhieu
*/

#include "raytracer.h"

int		delete_inter_list(t_inter *root)
{
  t_inter	*it;
  t_inter	*tmp;

  if (root == NULL)
    return (0);
  it = root;
  while (it != NULL)
    {
      tmp = it;
      it = it->next;
      bunny_free(tmp);
    }
  return (0);
}

t_csg		*init_tree_inters(t_csg *it)
{
  if (it->type == 0)
    {
      it->obj->inter = NULL;
    }
  if (it->left != NULL && it->right != NULL)
    {
      it->inter = NULL;
      if ((it->left = init_tree_inters(it->left)) == NULL)
	return (NULL);
      if ((it->right = init_tree_inters(it->right)) == NULL)
	return (NULL);
    }
  return (it);
}

t_csg		*free_tree_inters(t_csg *it)
{
  if (it->type == 0)
    {
      delete_inter_list(it->obj->inter);
      it->obj->inter = NULL;
    }
  if (it->left != NULL && it->right != NULL)
    {
      delete_inter_list(it->inter);
      it->inter = NULL;
      if ((it->left = free_tree_inters(it->left)) == NULL)
	return (NULL);
      if ((it->right = free_tree_inters(it->right)) == NULL)
	return (NULL);
    }
  return (it);
}
