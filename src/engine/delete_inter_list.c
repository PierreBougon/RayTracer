/*
** delete_inter_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sat May 21 06:34:30 2016 romain samuel
** Last update Sat May 21 23:40:58 2016 romain samuel
*/

#include "raytracer.h"

int		delete_inter_list(t_inter *left)
{
  if (left == NULL)
    return (0);
  free(left);
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
      it->obj->inter = NULL;
    }
  if (it->left != NULL && it->right != NULL)
    {
      it->inter = NULL;
      if ((it->left = free_tree_inters(it->left)) == NULL)
	return (NULL);
      if ((it->right = free_tree_inters(it->right)) == NULL)
	return (NULL);
    }
  return (it);
}
