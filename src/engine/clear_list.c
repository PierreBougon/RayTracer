/*
** clear_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 12 21:54:13 2016 romain samuel
** Last update Wed Apr 13 14:28:04 2016 romain samuel
*/

#include "raytracer.h"

int		clear_list(t_object *root)
{
  t_object	*it;

  if (root == NULL)
    return (0);
  if (root->next != NULL)
    {
      it = root;
      while (it->next != NULL)
	it = it->next;
      while (it != NULL)
	{
	  free(it->next);
	  it = it->prev;
	}
    }
  free(root);
  root = NULL;
  return (0);
}
