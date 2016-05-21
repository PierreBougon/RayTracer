/*
** create_obj_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 15:55:32 2016 romain samuel
** Last update Thu May  5 17:54:11 2016 romain samuel
*/

#include "raytracer.h"

t_object	*create_obj_list()
{
  t_object	*root;

  if ((root = bunny_malloc(sizeof(t_object))) == NULL)
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
  if ((new = bunny_malloc(sizeof(t_object))) == NULL)
    return (my_puterr("could not peform bunny_malloc"));
  it->next = new;
  new->prev = it;
  new->next = NULL;
  return (0);
}

t_object		*add_obj_elem_ret(t_object *root)
{
  t_object	*it;
  t_object	*new;

  it = root;
  while (it->next != NULL)
    it = it->next;
  if ((new = bunny_malloc(sizeof(t_object))) == NULL)
    return (my_puterror("could not peform bunny_malloc"));
  it->next = new;
  new->prev = it;
  new->next = NULL;
  return (new);
}
