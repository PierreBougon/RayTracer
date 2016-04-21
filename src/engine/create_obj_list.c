/*
** create_obj_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:55:32 2016 romain samuel
** Last update Sun Apr 10 14:16:16 2016 romain samuel
*/

#include "raytracer.h"

t_object	*create_obj_list()
{
  t_object	*root;

  if ((root = malloc(sizeof(t_object))) == NULL)
    return (my_puterror("could not perform bunny_malloc"));
  root->next = NULL;
  root->prev = NULL;
  return (root);
}

int		add_obj_elem(t_object *root)
{
  t_object	*it;
  t_object	*new;

  it = root;
  while (it->next != NULL)
    it = it->next;
  if ((new = malloc(sizeof(t_object))) == NULL)
    return (my_puterr("could not peform bunny_malloc"));
  it->next = new;
  new->prev = it;
  new->next = NULL;
  return (0);
}
