/*
** order_hit_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 10 20:49:25 2016 romain samuel
** Last update Mon May  2 17:16:02 2016 romain samuel
*/

#include "raytracer.h"

int		swap_objs(t_object *it, t_object *it_prev)
{
  it_prev->prev->next = it;
  if (it->next != NULL)
    it->next->prev = it_prev;
  it_prev->next = it->next;
  it->prev = it_prev->prev;
  it->next = it_prev;
  it_prev->prev = it;
  return (0);
}

int		order_list(t_object *root)
{
  t_object	*it;
  t_object	*it_prev;

  if (root == NULL || root->next == NULL || root->next->next == NULL)
    return (0);
  it = root->next->next;
  it_prev = root->next;
  while (it != NULL)
    {
      if (it->k < it_prev->k)
	{
	  swap_objs(it, it_prev);
	  return (-1);
	}
      it = it->next;
      it_prev = it_prev->next;
    }
  return (0);
}

int	order_hit_list(t_object *root)
{
  while (order_list(root) == -1);
  return (0);
}
