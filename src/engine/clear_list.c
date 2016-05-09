/*
** clear_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 12 21:54:13 2016 romain samuel
** Last update Sat May  7 19:00:57 2016 bougon_p
*/

#include "raytracer.h"

int		clear_list(t_object *root)
{
  t_object	*it;

  if (root == NULL)
    return (0);
  it = root->next;
  while (it->next != NULL)
    {
      it = it->next;
      bunny_free(it->prev);
    }
  bunny_free(root);
  bunny_free(it);
  return (0);
}
