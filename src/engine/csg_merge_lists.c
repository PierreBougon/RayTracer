/*
** csg_merge_lists.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu May 19 02:02:17 2016 romain samuel
** Last update Sun May 22 17:31:15 2016 benjamin duhieu
*/

#include "raytracer.h"

static void	set_it_value(t_inter *it_left, t_inter *it_right)
{
  it_left->k = it_right->k;
  it_left->simple_inter = it_right->simple_inter;
  it_left->norm = it_right->norm;
  it_left->sub = it_right->sub;
  it_left->del = it_right->del;
  it_left->obj = it_right->obj;
  it_left->exterior = it_right->exterior;
  it_right = it_right->next;
}

int		csg_merge_lists(t_inter *left, t_inter *right)
{
  t_inter	*it_left;
  t_inter	*it_right;

  if (right == NULL)
    return (0);
  it_right = right->next;
  left->k = 0;
  while (it_right != NULL)
    {
      it_left = left;
      while (it_left != NULL
	     && it_left->next != NULL)
	{
	  it_left = it_left->next;
	}
      if ((it_left = add_inter_elem(it_left)) == NULL)
	return (-1);
      set_it_value(it_left, it_right);
    }
  order_inter_list(left);
  delete_inter_elem(right);
  return (0);
}

int		set_csg_substraction(t_inter *left, t_inter *right)
{
  if (csg_clean_second_list(right) == -1)
    return (-1);
  if (right->next == NULL)
    return (-1);
  if (csg_merge_lists(left, right) == -1)
    return (-1);
  if (set_del_inters(left) == -1)
    return (-1);
  if (set_del_subs(left) == -1)
    return (-1);
  return (0);
}
