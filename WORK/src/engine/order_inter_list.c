/*
** order_inter_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu May 19 12:41:52 2016 romain samuel
** Last update Thu May 19 12:48:12 2016 romain samuel
*/

#include "raytracer.h"

static int		inter_swap_objs(t_inter *it, t_inter *it_prev)
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

static int	order_int_list(t_inter *root)
{
  t_inter	*it;
  t_inter	*it_prev;

  if (root == NULL || root->next == NULL || root->next->next == NULL)
    return (0);
  it = root->next->next;
  it_prev = root->next;
  while (it != NULL)
    {
      if (it->k < it_prev->k)
	{
	  inter_swap_objs(it, it_prev);
	  return (-1);
	}
      it = it->next;
      it_prev = it_prev->next;
    }
  return (0);
}

int	order_inter_list(t_inter *root)
{
  while (order_int_list(root) == -1);
  return (0);
}
