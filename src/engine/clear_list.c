/*
** clear_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 12 21:54:13 2016 romain samuel
** Last update Sat May 21 21:52:47 2016 bougon_p
*/

#include "raytracer.h"

void	free_data(UNUSED t_object *tmp)
{
  //des trucs
}

int		clear_list(t_object *root)
{
  t_object	*it;
  t_object	*tmp;

  if (root == NULL)
    return (0);
  it = root;
  while (it != NULL)
    {
      tmp = it;
      it = it->next;
      free_data(tmp);
      bunny_free(tmp);
    }
  return (0);
}
